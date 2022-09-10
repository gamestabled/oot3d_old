#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include <capstone/capstone.h>

#include "n3dsdisasm.h"

extern void fatal_error(const char *fmt, ...);

uint32_t ROM_LOAD_ADDR;
#define UNKNOWN_SIZE (uint32_t)-1

struct DepNode
{
    uint32_t addr;
    struct DepNode *next;
};

#define MAX_DEPS 50

struct Label
{
    uint32_t addr;
    uint8_t type;
    uint8_t branchType;
    uint32_t size;
    bool processed;
    bool isFunc; // 100% sure it's a function, which cannot be changed to BRANCH_TYPE_B. 
    char *name;
    struct DepNode *deps[MAX_DEPS]; // TODO: reimplement this
    int depCount;
    bool inactive;
    bool isFarJump;
};

struct Label *gLabels = NULL;
int gLabelsCount = 0;
static int sLabelBufferCount = 0;
static csh sCapstone;

const bool gOptionShowAddrComments = false;
const int gOptionDataColumnWidth = 16;

static struct Label *lookup_label(uint32_t addr);
static void renew_or_add_new_func_label(int type, uint32_t word);

int disasm_add_label(uint32_t addr, uint8_t type, char *name)
{
    int i, j;

    //printf("adding label 0x%08x\n", addr);
    // Search for label
    //assert(addr >= ROM_LOAD_ADDR && addr < ROM_LOAD_ADDR + gInputFileBufferSize);
    for (i = 0; i < gLabelsCount; i++)
    {
        if (gLabels[i].addr == addr)
        {
            gLabels[i].type = type;
            return i;
        }
    }

    i = gLabelsCount++;

    if (gLabelsCount > sLabelBufferCount) // need realloc
    {
        sLabelBufferCount = 2 * gLabelsCount;
        gLabels = realloc(gLabels, sLabelBufferCount * sizeof(*gLabels));

        if (gLabels == NULL)
            fatal_error("failed to alloc space for labels. ");
    }
    gLabels[i].addr = addr;
    gLabels[i].type = type;
    if (type == LABEL_ARM_CODE || type == LABEL_THUMB_CODE)
        gLabels[i].branchType = BRANCH_TYPE_BL;  // assume it's the start of a function
    else
        gLabels[i].branchType = BRANCH_TYPE_UNKNOWN;
    gLabels[i].size = UNKNOWN_SIZE;
    gLabels[i].processed = false;
    gLabels[i].name = name;
    gLabels[i].isFunc = false;
    for (j = 0; j < MAX_DEPS; ++j)
        gLabels[i].deps[j] = NULL;
    gLabels[i].depCount = 0;
    gLabels[i].inactive = false;
    gLabels[i].isFarJump = false;
    return i;
}

int disasm_set_branch_type(uint32_t addr, uint32_t type, bool farJump)
{
    struct Label *label = lookup_label(addr);
    if(!label) return 1;
    label->branchType = type;
    label->isFarJump = farJump;
    return 0;
}

void disasm_force_func(int idx)
{
    gLabels[idx].isFunc = true;
}

// Utility Functions

static struct Label *lookup_label(uint32_t addr)
{
    int i;

    for (i = 0; i < gLabelsCount; i++)
    {
        if (gLabels[i].addr == addr && !gLabels[i].inactive)
            return &gLabels[i];
    }
    return NULL;
}

static uint8_t byte_at(uint32_t addr)
{
    return gInputFileBuffer[addr - ROM_LOAD_ADDR];
}

static uint16_t hword_at(uint32_t addr)
{
    return (byte_at(addr + 0) << 0)
         | (byte_at(addr + 1) << 8);
}

static uint32_t word_at(uint32_t addr)
{
    return (byte_at(addr + 0) << 0)
         | (byte_at(addr + 1) << 8)
         | (byte_at(addr + 2) << 16)
         | (byte_at(addr + 3) << 24);
}

static int get_unprocessed_label_index(void)
{
    int i;

    for (i = 0; i < gLabelsCount; i++)
    {
        if (!gLabels[i].processed && !gLabels[i].inactive)
            return i;
    }
    return -1;
}

static bool is_branch(const struct cs_insn *insn)
{
    switch (insn->id)
    {
    case ARM_INS_B:
    case ARM_INS_BX:
    case ARM_INS_BL:
        return true;
    }
    return false;
}

static bool is_func_return(const struct cs_insn *insn)
{
    const struct cs_arm *arminsn = &insn->detail->arm;

    // 'bx' instruction
    if (insn->id == ARM_INS_BX)
        return arminsn->cc == ARM_CC_AL;
    // 'mov' with pc as the destination
    if (insn->id == ARM_INS_MOV
     && arminsn->operands[0].type == ARM_OP_REG
     && arminsn->operands[0].reg == ARM_REG_PC)
        return true;
    // 'pop' with pc in the register list
    if (insn->id == ARM_INS_POP)
    {
        int i;

        assert(arminsn->op_count > 0);
        for (i = 0; i < arminsn->op_count; i++)
        {
            if (arminsn->operands[i].type == ARM_OP_REG
             && arminsn->operands[i].reg == ARM_REG_PC)
                return true;
        }
    }
    return false;
}

static bool is_pool_load(const struct cs_insn *insn)
{
    const struct cs_arm *arminsn = &insn->detail->arm;

    if (insn->id == ARM_INS_LDR
     && arminsn->operands[0].type == ARM_OP_REG
     && arminsn->operands[1].type == ARM_OP_MEM
     && !arminsn->operands[1].subtracted
     && arminsn->operands[1].mem.base == ARM_REG_PC
     && arminsn->operands[1].mem.index == ARM_REG_INVALID)
        return true;
    else
        return false;
}

static uint32_t get_pool_load(const struct cs_insn *insn, uint32_t currAddr, int mode)
{
    assert(is_pool_load(insn));

    return (currAddr & ~3) + insn->detail->arm.operands[1].mem.disp + ((mode == LABEL_ARM_CODE) ? 8 : 4);
}

static uint32_t get_branch_target(const struct cs_insn *insn)
{
    assert(is_branch(insn));
    assert(insn->detail != NULL);

    return insn->detail->arm.operands[0].imm;
}

// Code Analysis

static int sJumpTableState = 0;

static void jump_table_state_machine(const struct cs_insn *insn, uint32_t addr)
{
    static uint32_t jumpTableBegin;
    // sometimes another instruction (like a mov) can interrupt
    static bool gracePeriod;
    static uint32_t poolAddr;
    static arm_reg targetReg;

    switch (sJumpTableState)
    {
      case 0:
        // "lsl rX, rX, 2"
        gracePeriod = false;
        if (insn->id == ARM_INS_LSL)
            goto match;
        break;
      case 1:
        // "ldr rX, [pc, ?]"
        if (is_pool_load(insn))
        {
            poolAddr = get_pool_load(insn, addr, LABEL_THUMB_CODE);
            jumpTableBegin = word_at(poolAddr);
            goto match;
        }
        break;
      case 2:
        // "add rX, rX, rX"
        if (insn->id == ARM_INS_ADD)
            goto match;
        break;
      case 3:
        // "ldr rX, [rX]"
        if (insn->id == ARM_INS_LDR
            && insn->detail->arm.operands[0].type == ARM_OP_REG)
        {
            targetReg = insn->detail->arm.operands[0].reg;
            goto match;
        }
        break;
      case 4:
        // "mov pc, rX"
        if (insn->id == ARM_INS_MOV
         && insn->detail->arm.operands[0].type == ARM_OP_REG
         && insn->detail->arm.operands[0].reg == ARM_REG_PC
         && insn->detail->arm.operands[1].type == ARM_OP_REG
         && insn->detail->arm.operands[1].reg == targetReg
         && insn->detail->arm.operands[1].shift.type == ARM_SFT_INVALID)
            goto match;
        break;
    }

    // didn't match
    if (gracePeriod)
        sJumpTableState = 0;
    else
        gracePeriod = true;
    return;

  match:
    if (sJumpTableState == 4)  // all checks passed
    {
        uint32_t target;
        uint32_t firstTarget = -1u;

        disasm_add_label(jumpTableBegin, LABEL_JUMP_TABLE, NULL);
        sJumpTableState = 0;
        // add code labels from jump table
        addr = jumpTableBegin;
        while (addr < firstTarget)
        {
            int label;

            target = word_at(addr);
            if (target - ROM_LOAD_ADDR >= gInputFileBufferSize)
                break;
            if (target < firstTarget && target > jumpTableBegin)
                firstTarget = target;
            label = disasm_add_label(target, LABEL_THUMB_CODE, NULL);
            gLabels[label].branchType = BRANCH_TYPE_B;
            addr += 4;
        }

        return;
    }
    sJumpTableState++;
}

// when the size of a jump table is provided
int jump_table_create_labels(uint32_t start, int count)
{
    uint32_t end, addr, target;
    int idx;

    if (count <= 0 || start & 3) return 1;
    end = start + count * 4;
    for (addr = start; addr < end; addr += 4)
    {
        target = word_at(addr);
        if (target - ROM_LOAD_ADDR >= gInputFileBufferSize
            || target < end)
            return 1;
        idx = disasm_add_label(target, LABEL_THUMB_CODE, NULL);
        gLabels[idx].branchType = BRANCH_TYPE_B;
    }
    return 0;
}

static struct DepNode sInvalidDepNode = {0};

static void rec_free_dep_nodes(struct DepNode *);

// return true if a dep linked list is marked as invalid
static bool scan_func_in_deps(struct Label *pool, struct Label *func)
{
    struct DepNode **cur;
    bool ret = false;
    int i;

    for (i = 0; i < pool->depCount; ++i)
    {
        for (cur = &pool->deps[i]; *cur; cur = &(*cur)->next)
        {
            if ((*cur)->addr == func->addr) // This linked list is invalid
            {
                rec_free_dep_nodes(pool->deps[i]);
                pool->deps[i] = &sInvalidDepNode;
                ret = true;
                break; // process next linked list
            }
        }
    }
    return ret;
}

static void add_dep_to_dep_entry(struct DepNode **depNodePtrLoc, uint32_t func)
{
    struct DepNode **cur;

    for (cur = depNodePtrLoc; *cur; cur = &(*cur)->next)
        if ((*cur)->addr == func)
            return;
    *cur = malloc(sizeof(struct DepNode));
    if (!*cur)
        fatal_error("failed to alloc buffer for function 0x%x", func);
    (*cur)->addr = func;
    (*cur)->next = NULL;
}

static void rec_free_dep_nodes(struct DepNode *dn)
{
    if (!dn) return;
    rec_free_dep_nodes(dn->next);
    free(dn);
}

static void remove_label(struct Label *label)
{
    label->inactive = true;
}

static struct Label *find_prev_label(struct Label *label)
{
    struct Label *ret = NULL;
    int i;

    for (i = 0; i < gLabelsCount; ++i)
    {
        if (gLabels[i].type == LABEL_THUMB_CODE || gLabels[i].type == LABEL_ARM_CODE)
        {
            if (gLabels[i].addr < label->addr && !gLabels[i].inactive)
            {
                if (!ret
                    || gLabels[i].addr > ret->addr)
                    ret = &gLabels[i];
            }
        }
    }
    return ret;
}

static void update_label_dep_with_fake_func(struct Label *fake)
{
    int i;

    for (i = 0; i < gLabelsCount; ++i)
        scan_func_in_deps(&gLabels[i], fake);
}

// return true if there's still at least 1 label for processing
static bool set_inactive_labels_and_reprocess_prev_labels(void)
{
    int i, j;
    bool ret = false;

    for (i = 0; i < gLabelsCount; ++i)
    {
        if (!gLabels[i].inactive && gLabels[i].depCount)
        {
            for (j = 0; j < gLabels[i].depCount; ++j)
            {
                if (gLabels[i].deps[j] != &sInvalidDepNode) // There's still at least one path valid => label is valid (even if NULL)
                    break;
            }
            if (j == gLabels[i].depCount) // no valid path found
            {
                struct Label *label = find_prev_label(&gLabels[i]);

                ret = true;
                if (label)
                    label->processed = false;
                remove_label(&gLabels[i]);
            }
        }
    }
    return ret;
}

// handle mov lr, pc; bx rX
static bool is_gs_func_call(const cs_insn *insn, uint32_t addr, int type) // should be called only when there's at least one function following
{
    if (insn[1].id != ARM_INS_BX)
        return false;
    if (insn[0].id == ARM_INS_MOV
        && insn[0].detail->arm.cc == ARM_CC_AL
        && insn[0].detail->arm.op_count == 2
        && insn[0].detail->arm.operands[0].type == ARM_OP_REG
        && insn[0].detail->arm.operands[0].reg == ARM_REG_LR
        && insn[0].detail->arm.operands[1].type == ARM_OP_REG
        && insn[0].detail->arm.operands[1].reg == ARM_REG_PC
        && insn[0].detail->arm.operands[1].shift.type == ARM_SFT_INVALID)
    {
        if (type == LABEL_THUMB_CODE)
            // TODO: this is unsafe. Possibly a thumb subroutine will return with something like mov pc, lr
            renew_or_add_new_func_label(LABEL_ARM_CODE, (addr + 2) & ~2); // the bx insn can be used for both thumb and arm
        return true;
    }
    if (insn[0].id == ARM_INS_ADD
        && insn[0].detail->arm.cc == ARM_CC_AL
        && insn[0].detail->arm.op_count == 3
        && insn[0].detail->arm.operands[0].type == ARM_OP_REG
        && insn[0].detail->arm.operands[0].reg == ARM_REG_LR
        && insn[0].detail->arm.operands[1].type == ARM_OP_REG
        && insn[0].detail->arm.operands[1].reg == ARM_REG_PC
        && insn[0].detail->arm.operands[2].type == ARM_OP_IMM)
    {
        // only ARM insns can reach here
        if (insn[0].detail->arm.operands[2].imm == 0)
            return true;
        if (!lookup_label(addr + insn[0].detail->arm.operands[2].imm))
        {
            int idx = disasm_add_label(addr + insn[0].detail->arm.operands[2].imm, type, NULL);
            gLabels[idx].branchType = BRANCH_TYPE_B;
        }
    }
    return false;
}

static void renew_or_add_new_func_label(int type, uint32_t word)
{
    if (word >= ROM_LOAD_ADDR && word - ROM_LOAD_ADDR < gInputFileBufferSize - 4)
    {
        struct Label *label_p = lookup_label(word & ~1);

        if (label_p != NULL)
        {
            // maybe it has been processed as a non-function label
            label_p->processed = false;
            label_p->branchType = BRANCH_TYPE_BL;
            label_p->isFunc = true;
        }
        else
        {
            // implicitly set to BRANCH_TYPE_BL
            int idx = disasm_add_label(word & ~1, type, NULL);
            gLabels[idx].isFunc = true;
        }
    }
}

static bool IsValidInstruction(cs_insn * insn, int type)
{
    if (cs_insn_group(sCapstone, insn, ARM_GRP_VFP2))
        return true;
    if (type == LABEL_ARM_CODE) {
        return cs_insn_group(sCapstone, insn, ARM_GRP_ARM);
    } else {
        return cs_insn_group(sCapstone, insn, ARM_GRP_THUMB);
    }
}

static uint32_t next_label_addr(uint32_t addr)
{
    uint32_t labelAddr = 0xFFFFFFFF;
    int i;

    for (i = 0; i < gLabelsCount; ++i)
    {
        if (gLabels[i].addr == addr
         && (gLabels[i].type == LABEL_ARM_CODE || gLabels[i].type == LABEL_THUMB_CODE))
            continue;

        if (gLabels[i].addr >= addr
         && gLabels[i].addr < labelAddr
         && !gLabels[i].inactive)
            labelAddr = gLabels[i].addr;
    }
    return labelAddr == 0xFFFFFFFF ? 0 : labelAddr;
}

static void analyze(void)
{
    while (1)
    {
        int li;
        int i;
        uint32_t addr;
        int type;
        struct cs_insn *insn;
        const int dismAllocSize = 0x1000;
        int count;

        if ((li = get_unprocessed_label_index()) == -1)
        {
            if (!set_inactive_labels_and_reprocess_prev_labels() // important -- only mark inactive when there's nothing to process. 
                || (li = get_unprocessed_label_index()) == -1)
                return;
        }
        addr = gLabels[li].addr;
        type = gLabels[li].type;

        if (type == LABEL_ARM_CODE || type == LABEL_THUMB_CODE)
        {
            cs_option(sCapstone, CS_OPT_MODE, (type == LABEL_ARM_CODE) ? CS_MODE_ARM : CS_MODE_THUMB);
            sJumpTableState = 0;
            //fprintf(stderr, "analyzing label at 0x%08x\n", addr);
            do
            {
                // Note: This is a mitigation instead of solution. 
                /*
                 * Remaining BUG Scenario: 
                 * (.code 16)
                 * label_A:
                 *     (code)
                 *     ldr rX, pool_A
                 *     (code)
                 * label_B:
                 *     (code)
                 *     bl somewhere @ far jump, not a procedure call
                 * pool_A:
                 *     .long ...
                 * Unluckily, label_B is processed before label_A so it doesn't know pool_A is a pool,
                 * so it keeps disassembling until it hits something that can break out of the current
                 * code chunk iteration. It's usually not a problem but something in the data pool may
                 * be diassembled to ldr, resulting in registering an incorrect pool label, which screws
                 * up later analysis. 
                 */
                uint32_t labelAddr = next_label_addr(addr);
                #define MAX_CALL 1000
                uint32_t processedCallsInChunk[MAX_CALL] = {0}; // TODO: reimplement this
                int pcici = 0;

                if (labelAddr <= addr && labelAddr != 0)
                    break;
                count = cs_disasm(sCapstone, gInputFileBuffer + addr - ROM_LOAD_ADDR, labelAddr == 0 ? 0x1000 : labelAddr - addr, addr, 0, &insn);
                for (i = 0; i < count; i++)
                {
                    uint32_t nextAddr = next_label_addr(addr);

                    if (labelAddr > nextAddr) labelAddr = nextAddr;
                    if (labelAddr <= addr && labelAddr != 0)
                        break;
                  no_inc:
                    if (!IsValidInstruction(&insn[i], type)) {
                        if (type == LABEL_THUMB_CODE)
                        {
                            int tmp_cnt;
                            cs_insn * tmp;
                            addr += 2;
                            if (insn[i].size == 2) continue;
                            tmp_cnt = cs_disasm(sCapstone, gInputFileBuffer + addr - ROM_LOAD_ADDR, 2, addr, 0, &tmp);
                            assert(tmp_cnt == 1);
                            free(insn[i].detail);
                            insn[i] = *tmp;
                            free(tmp);
                            goto no_inc;
                        }
                        else
                        {
                            addr += 4;
                            continue;
                        }
                    };
                    jump_table_state_machine(&insn[i], addr);

                    // fprintf(stderr, "/*0x%08x*/ %s %s\n", addr, insn[i].mnemonic, insn[i].op_str);
                    if (is_branch(&insn[i]))
                    {
                        uint32_t target;
                        //uint32_t currAddr = addr;

                        // handle bx pc
                        if (insn[i].id == ARM_INS_BX
                            && insn[i].detail->arm.op_count == 1
                            && insn[i].detail->arm.operands[0].type == ARM_OP_REG
                            && insn[i].detail->arm.operands[0].reg == ARM_REG_PC)
                        {
                            renew_or_add_new_func_label(LABEL_ARM_CODE, 4 + (addr&~3));
                            addr += insn[i].size;
                            break;
                        }

                        addr += insn[i].size;

                        // For BX{COND}, only BXAL can be considered as end of function
                        if (is_func_return(&insn[i]))
                        {
                            struct Label *label_p;

                            if (i && is_gs_func_call(&insn[i-1], addr, type)) continue;

                            // It's possible that handwritten code with different mode follows. 
                            // However, this only causes problem when the address following is
                            // incorrectly labeled as BRANCH_TYPE_B. 
                            label_p = lookup_label(addr);
                            if (label_p != NULL
                             && (label_p->type == LABEL_THUMB_CODE || label_p->type == LABEL_ARM_CODE)
                             && label_p->type != type
                             && label_p->branchType == BRANCH_TYPE_B)
                            {
                                label_p->branchType = BRANCH_TYPE_BL;
                                label_p->isFunc = true;
                            }
                            break;
                        }

                        if (insn[i].id == ARM_INS_BX) // BX{COND} when COND != AL
                            continue;

                        target = get_branch_target(&insn[i]);
                        assert(target != 0);

                        // I don't remember why I needed this condition
                        //if (!(target >= gLabels[li].addr && target <= currAddr))
                        if (1)
                        {
                            int lbl = disasm_add_label(target, type, NULL);

                            if (!gLabels[lbl].isFunc) // do nothing if it's 100% a func (from func ptr, or instant mode exchange)
                            {
                                if (insn[i].id == ARM_INS_BL)
                                {
                                    const struct Label *next;

                                    if (gLabels[lbl].branchType != BRANCH_TYPE_B)
                                    {
                                        int j;

                                        gLabels[lbl].branchType = BRANCH_TYPE_BL;
                                        for (j = 0; j < pcici; ++j)
                                            if (processedCallsInChunk[j] == gLabels[lbl].addr)
                                                break;
                                        if (j == pcici && pcici < MAX_CALL)
                                            processedCallsInChunk[pcici++] = gLabels[lbl].addr;
                                    }
                                    else if (insn[i].detail->arm.cc == ARM_CC_AL
                                        && gLabels[lbl].isFarJump)
                                        break;
                                    // if the address right after is a pool, then we know
                                    // for sure that this is a far jump and not a function call
                                    if (((next = lookup_label(addr)) != NULL && next->type == LABEL_POOL)
                                    // if the 2 bytes following are zero, assume it's padding
                                    // Note that we need to make sure it's not 4-byte aligned since we can now be in ARM mode
                                     || ((addr & 2) && hword_at(addr) == 0))
                                    {
                                        gLabels[lbl].isFarJump = true;
                                        gLabels[lbl].branchType = BRANCH_TYPE_B;
                                        update_label_dep_with_fake_func(&gLabels[lbl]);
                                        break;
                                    }
                                }
                                else
                                {
                                    // the label might be given a name in .cfg file, but it's actually not a function
                                    if (gLabels[lbl].name != NULL)
                                        free(gLabels[lbl].name);
                                    gLabels[lbl].name = NULL;
                                    gLabels[lbl].branchType = BRANCH_TYPE_B;
                                }
                            }
                        }

                        // unconditional jump and not a function call
                        if (insn[i].detail->arm.cc == ARM_CC_AL && insn[i].id != ARM_INS_BL)
                            break;
                    }
                    else
                    {
                        uint32_t poolAddr;
                        uint32_t word;

                        addr += insn[i].size;

                        if (is_func_return(&insn[i]))
                        {
                            struct Label *label_p;

                            // It's possible that handwritten code with different mode follows. 
                            // However, this only causes problem when the address following is
                            // incorrectly labeled as BRANCH_TYPE_B. 
                            label_p = lookup_label(addr);
                            if (label_p != NULL
                             && (label_p->type == LABEL_THUMB_CODE || label_p->type == LABEL_ARM_CODE)
                             && label_p->type != type
                             && label_p->branchType == BRANCH_TYPE_B)
                            {
                                label_p->branchType = BRANCH_TYPE_BL;
                                label_p->isFunc = true;
                            }
                            break;
                        }

                        assert(insn[i].detail != NULL);

                        // looks like that this check can only detect thumb mode
                        // anyway I still put the arm mode things here for a potential future fix
                        if (insn[i].id == ARM_INS_ADR)
                        {
                            word = insn[i].detail->arm.operands[1].imm + (addr - insn[i].size)
                                 + (type == LABEL_THUMB_CODE ? 4 : 8);
                            if (type == LABEL_THUMB_CODE)
                                word &= ~3;
                            goto check_handwritten_indirect_jump;
                        }

                        // fix above check for arm mode
                        if (type == LABEL_ARM_CODE
                         && insn[i].id == ARM_INS_ADD
                         && insn[i].detail->arm.operands[0].type == ARM_OP_REG
                         && insn[i].detail->arm.operands[1].type == ARM_OP_REG
                         && insn[i].detail->arm.operands[1].reg == ARM_REG_PC
                         && insn[i].detail->arm.operands[2].type == ARM_OP_IMM)
                        {
                            word = insn[i].detail->arm.operands[2].imm + (addr - insn[i].size) + 8;
                            goto check_handwritten_indirect_jump;
                        }

                        if (is_pool_load(&insn[i]))
                        {
                            int j, k;
                            bool flag;
                            int idx;
                            struct DepNode **dn;

                            poolAddr = get_pool_load(&insn[i], addr - insn[i].size, type);
                            assert(poolAddr != 0);
                            assert((poolAddr & 3) == 0);

                            // check if anything in PCIC is already proved a far jump
                            flag = false;
                            for (j = 0; j < gLabelsCount; ++j)
                            {
                                for (k = 0; k < pcici; ++k)
                                {
                                    if (processedCallsInChunk[k] == gLabels[j].addr
                                        && gLabels[j].isFarJump)
                                    {
                                        flag = true;
                                        break;
                                    }
                                }
                                if (flag) break;
                            }
                            if (flag) continue; // simply ignore this pool
                            // otherwise we add another dep linked list to the pool label
                            idx = disasm_add_label(poolAddr, LABEL_POOL, NULL);
                            gLabels[idx].inactive = false;
                            if (gLabels[idx].depCount == MAX_DEPS)
                            {
                                // try to replace an invalid pointer
                                for (j = 0; j < gLabels[idx].depCount; ++j)
                                    if (gLabels[idx].deps[j] == &sInvalidDepNode)
                                        break;
                                if (j == MAX_DEPS) // really, no slot available
                                    continue; // simply ignore it -- usually this is fine because we have tons of deps
                                dn = &gLabels[idx].deps[j];
                                *dn = NULL;
                            }
                            else
                            {
                                dn = &gLabels[idx].deps[gLabels[idx].depCount];
                                ++gLabels[idx].depCount;
                            }
                            for (k = 0; k < pcici; ++k)
                                add_dep_to_dep_entry(dn, processedCallsInChunk[k]);

                            if (poolAddr < labelAddr && poolAddr > addr - insn[i].size)
                                labelAddr = poolAddr;
                            word = word_at(poolAddr);

                        check_handwritten_indirect_jump:
                            if (i < count - 1) // is not last insn in the chunk
                            {   
                                // check if it's followed with bx RX or mov PC, RX (conditional won't hurt)
                                if (insn[i + 1].id == ARM_INS_BX)
                                {
                                    if (insn[i + 1].detail->arm.operands[0].type == ARM_OP_REG
                                     && insn[i].detail->arm.operands[0].reg == insn[i + 1].detail->arm.operands[0].reg)
                                        renew_or_add_new_func_label(word & 1 ? LABEL_THUMB_CODE : LABEL_ARM_CODE, word);
                                }
                                else if (insn[i + 1].id == ARM_INS_MOV
                                      && insn[i + 1].detail->arm.operands[0].type == ARM_OP_REG
                                      && insn[i + 1].detail->arm.operands[0].reg == ARM_REG_PC
                                      && insn[i + 1].detail->arm.operands[1].type == ARM_OP_REG
                                      && insn[i].detail->arm.operands[0].reg == insn[i + 1].detail->arm.operands[1].reg)
                                {
                                    renew_or_add_new_func_label(type, word);
                                }
                                
                            }
                        }
                    }
                }
                cs_free(insn, count);
            } while (count == dismAllocSize);
            gLabels[li].processed = true;
            gLabels[li].size = addr - gLabels[li].addr;
        }
        gLabels[li].processed = true;
    }
}

// Disassembly Output

static void print_gap(uint32_t addr, uint32_t nextaddr)
{
    if (addr == nextaddr)
        return;

    assert(addr < nextaddr);

    if ((addr & 3) == 2) {
        uint16_t next_short = hword_at(addr);
        if (next_short == 0) {
            fputs("\t.align 2, 0\n", stdout);
            addr += 2;
        } else if (next_short == 0x46C0) {
            fputs("\tnop\n", stdout);
            addr += 2;
        }
        if (addr == nextaddr) {
            return;
        }
    }

    printf("_%08x:\n", addr);
    if (addr % gOptionDataColumnWidth != 0)
        fputs("\t.byte", stdout);
    while (addr < nextaddr)
    {
        if (addr % gOptionDataColumnWidth == 0)
            fputs("\t.byte", stdout);
        if (addr % gOptionDataColumnWidth == (unsigned int)(gOptionDataColumnWidth - 1)
         || addr == nextaddr - 1)
            printf(" 0x%02x\n", byte_at(addr));
        else
            printf(" 0x%02x,", byte_at(addr));
        addr++;
    }
}

static void print_insn(const cs_insn *insn, uint32_t addr, int mode)
{
    if (gOptionShowAddrComments)
    {
        printf("\t/*0x%08x*/ %s %s\n", addr, insn->mnemonic, insn->op_str);
    }
    else
    {
        if (is_branch(insn) && insn->id != ARM_INS_BX)
        {
            uint32_t target = get_branch_target(insn);
            struct Label *label = lookup_label(target);

            assert(label != NULL);  // We should have found this label in the analysis phase
            if (label->name != NULL)
                printf("\t%s %s\n", insn->mnemonic, label->name);
            else
                printf("\t%s %s_%08x\n", insn->mnemonic, label->branchType == BRANCH_TYPE_BL ? "func" : "", target);
        }
        else if (is_pool_load(insn))
        {
            uint32_t word = get_pool_load(insn, addr, mode);
            uint32_t value = word_at(word);
            const struct Label *label_p;

            if (value & 3 && value > ROM_LOAD_ADDR && value - ROM_LOAD_ADDR - 1 < gInputFileBufferSize) // possibly thumb function
            {
                if (label_p = lookup_label(value & ~1), label_p != NULL)
                {
                    if (label_p->branchType == BRANCH_TYPE_BL && label_p->type == LABEL_THUMB_CODE)
                    {
                        if (label_p->name != NULL)
                            printf("\t%s %s, _%08x @ =%s\n", insn->mnemonic, cs_reg_name(sCapstone, insn->detail->arm.operands[0].reg), word, label_p->name);
                        else
                            printf("\t%s %s, _%08x @ =func_%08x\n", insn->mnemonic, cs_reg_name(sCapstone, insn->detail->arm.operands[0].reg), word, value & ~1);
                        return;
                    }
                }
            }
            label_p = lookup_label(value);
            if (label_p != NULL)
            {
                if (label_p->type != LABEL_THUMB_CODE)
                {
                    if (label_p->name != NULL)
                        printf("\t%s %s, _%08x @ =%s\n", insn->mnemonic, cs_reg_name(sCapstone, insn->detail->arm.operands[0].reg), word, label_p->name);
                    else if (label_p->branchType == BRANCH_TYPE_BL)
                        printf("\t%s %s, _%08x @ =func_%08x\n", insn->mnemonic, cs_reg_name(sCapstone, insn->detail->arm.operands[0].reg), word, value);
                    else // normal label
                        printf("\t%s %s, _%08x @ =_%08x\n",
                          insn->mnemonic, cs_reg_name(sCapstone, insn->detail->arm.operands[0].reg), word, value);
                    return;
                }
            }
            printf("\t%s %s, _%08x @ =0x%08x\n", insn->mnemonic, cs_reg_name(sCapstone, insn->detail->arm.operands[0].reg), word, value);
        }
        else
        {
            // fix "add rX, sp, rX"
            if (insn->id == ARM_INS_ADD
             && insn->detail->arm.operands[0].type == ARM_OP_REG
             && insn->detail->arm.operands[1].type == ARM_OP_REG
             && insn->detail->arm.operands[1].reg == ARM_REG_SP
             && insn->detail->arm.operands[2].type == ARM_OP_REG)
            {
                printf("\t%s %s, %s\n",
                  insn->mnemonic,
                  cs_reg_name(sCapstone, insn->detail->arm.operands[0].reg),
                  cs_reg_name(sCapstone, insn->detail->arm.operands[1].reg));
            }
            // fix thumb adr
            else if (insn->id == ARM_INS_ADR && mode == LABEL_THUMB_CODE)
            {
                uint32_t word = (insn->detail->arm.operands[1].imm + addr + 4) & ~3;
                const struct Label *label_p = lookup_label(word);

                if (label_p != NULL)
                {
                    if (label_p->type != LABEL_THUMB_CODE)
                    {
                        if (label_p->name != NULL)
                            printf("\tadd %s, pc, #0x%x @ =%s\n", cs_reg_name(sCapstone, insn->detail->arm.operands[0].reg), insn->detail->arm.operands[1].imm, label_p->name);
                        else if (label_p->branchType == BRANCH_TYPE_BL)
                            printf("\tadd %s, pc, #0x%x @ =func_%08x\n", cs_reg_name(sCapstone, insn->detail->arm.operands[0].reg), insn->detail->arm.operands[1].imm, word);
                        else
                            printf("\tadd %s, pc, #0x%x @ =_%08x\n", cs_reg_name(sCapstone, insn->detail->arm.operands[0].reg), insn->detail->arm.operands[1].imm, word);
                        return;
                    }
                }
                printf("\tadd %s, pc, #0x%x\n", cs_reg_name(sCapstone, insn->detail->arm.operands[0].reg), insn->detail->arm.operands[1].imm);
            }
            // arm adr
            else if (mode == LABEL_ARM_CODE
                  && insn->id == ARM_INS_ADD
                  && insn->detail->arm.operands[0].type == ARM_OP_REG
                  && insn->detail->arm.operands[1].type == ARM_OP_REG
                  && insn->detail->arm.operands[1].reg == ARM_REG_PC
                  && insn->detail->arm.operands[2].type == ARM_OP_IMM)
            {
                uint32_t word = insn->detail->arm.operands[2].imm + addr + 8;
                const struct Label *label_p;

                if (word & 3 && word > ROM_LOAD_ADDR && word - ROM_LOAD_ADDR - 1 < gInputFileBufferSize) // possibly thumb function
                {
                    if (label_p = lookup_label(word & ~1), label_p != NULL)
                    {
                        if (label_p->branchType == BRANCH_TYPE_BL && label_p->type == LABEL_THUMB_CODE)
                        {
                            if (label_p->name != NULL)
                                printf("\tadd %s, pc, #0x%x @ =%s\n", cs_reg_name(sCapstone, insn->detail->arm.operands[0].reg), insn->detail->arm.operands[2].imm, label_p->name);
                            else
                                printf("\tadd %s, pc, #0x%x @ =func_%08x\n", cs_reg_name(sCapstone, insn->detail->arm.operands[0].reg), insn->detail->arm.operands[2].imm, word & ~1);
                            return;
                        }
                    }
                }
                label_p = lookup_label(word);
                if (label_p != NULL)
                {
                    if (label_p->type != LABEL_THUMB_CODE)
                    {
                        if (label_p->name != NULL)
                            printf("\tadd %s, pc, #0x%x @ =%s\n", cs_reg_name(sCapstone, insn->detail->arm.operands[0].reg), insn->detail->arm.operands[2].imm, label_p->name);
                        else if (label_p->branchType == BRANCH_TYPE_BL)
                            printf("\tadd %s, pc, #0x%x @ =func_%08x\n", cs_reg_name(sCapstone, insn->detail->arm.operands[0].reg), insn->detail->arm.operands[2].imm, word);
                        else
                            printf("\tadd %s, pc, #0x%x @ =_%08x\n", cs_reg_name(sCapstone, insn->detail->arm.operands[0].reg), insn->detail->arm.operands[2].imm, word);
                        return;
                    }
                }
                printf("\tadd %s, pc, #0x%x @ =0x%08x\n", cs_reg_name(sCapstone, insn->detail->arm.operands[0].reg), insn->detail->arm.operands[2].imm, word);
            }
            else
                printf("\t%s %s\n", insn->mnemonic, insn->op_str);
        }
    }
}

static int qsort_label_compare(const void *a, const void *b)
{
    return ((struct Label *)a)->addr - ((struct Label *)b)->addr;
}

static void print_disassembly(void)
{
    uint32_t addr = ROM_LOAD_ADDR;
    int i = 0;

    qsort(gLabels, gLabelsCount, sizeof(*gLabels), qsort_label_compare);

    for (i = 0; i < gLabelsCount - 1; i++)
        assert(gLabels[i].addr < gLabels[i + 1].addr);
    for (i = 0; i < gLabelsCount; i++)
    {
        if (gLabels[i].type == LABEL_ARM_CODE || gLabels[i].type == LABEL_THUMB_CODE)
            assert(gLabels[i].processed);
    }
    // check mode exchange right after func return
    for (i = 1; i < gLabelsCount; i++)
        if ((gLabels[i - 1].type == LABEL_ARM_CODE && gLabels[i].type == LABEL_THUMB_CODE)
         || (gLabels[i - 1].type == LABEL_THUMB_CODE && gLabels[i].type == LABEL_ARM_CODE))
            gLabels[i].branchType = BRANCH_TYPE_BL;

    // remove inactive labels

    for (i = 0; i < gLabelsCount; i++)
    {
        int j;

        if (gLabels[i].inactive)
        {
            for (j = 0; j < gLabels[i].depCount && gLabels[i].deps[j]; ++j)
                if (gLabels[i].deps[j] != &sInvalidDepNode)
                    rec_free_dep_nodes(gLabels[i].deps[j]);
            if (i+1 < gLabelsCount)
            {
                memmove(&gLabels[i], &gLabels[i+1], sizeof(struct Label) * (gLabelsCount - i - 1));
                --i; // don't increment i
            }
            --gLabelsCount;
        }
    }

    i = 0;
    while (addr < ROM_LOAD_ADDR + gInputFileBufferSize)
    {
        uint32_t nextAddr;

        // TODO: compute actual size during analysis phase
        if (i + 1 < gLabelsCount)
        {
            if (gLabels[i].size == UNKNOWN_SIZE
             || gLabels[i].addr + gLabels[i].size > gLabels[i + 1].addr)
                gLabels[i].size = gLabels[i + 1].addr - gLabels[i].addr;
        }

        // may only happen when ROM_LOAD_ADDR is not labeled
        if (addr < gLabels[i].addr)
        {
            print_gap(addr, gLabels[i].addr);
            addr = gLabels[i].addr;
        }

        switch (gLabels[i].type)
        {
        case LABEL_ARM_CODE:
        case LABEL_THUMB_CODE:
            {
                struct cs_insn *insn;
                int count;
                int j;
                int mode = (gLabels[i].type == LABEL_ARM_CODE) ? CS_MODE_ARM : CS_MODE_THUMB;

                // This is a function. Use the 'func_XXXXXXXX' label
                if (gLabels[i].branchType == BRANCH_TYPE_BL)
                {
                    unsigned int unalignedMask = (mode == CS_MODE_ARM) ? 3 : 1;

                    if (addr & unalignedMask)
                    {
                        fprintf(stderr, "error: function at 0x%08x is not aligned\n", addr);
                        return;
                    }
                    if (gLabels[i].name != NULL)
                    {
                        printf("\n\t%s %s\n",
                          (gLabels[i].type == LABEL_ARM_CODE) ? "arm_func_start" : (addr & 2 ? "non_word_aligned_thumb_func_start" : "thumb_func_start"),
                          gLabels[i].name);
                        printf("%s: @ 0x%08x\n", gLabels[i].name, addr);
                    }
                    else
                    {
                        printf("\n\t%s func_%08x\n",
                          (gLabels[i].type == LABEL_ARM_CODE) ? "arm_func_start" : (addr & 2 ? "non_word_aligned_thumb_func_start" : "thumb_func_start"),
                          addr);
                        printf("func_%08x: @ 0x%08x\n", addr, addr);
                    }
                }
                // Just a normal code label. Use the '_XXXXXXXX' label
                else
                {
                    if (gLabels[i].name != NULL)
                        printf("%s:\n", gLabels[i].name);
                    else
                        printf("_%08x:\n", addr);
                }
                assert(gLabels[i].size != UNKNOWN_SIZE);
                cs_option(sCapstone, CS_OPT_MODE, mode);
                count = cs_disasm(sCapstone, gInputFileBuffer + addr - ROM_LOAD_ADDR, gLabels[i].size, addr, 0, &insn);
                for (j = 0; j < count; j++)
                {
                  no_inc:
                    if (!IsValidInstruction(&insn[j], gLabels[i].type)) {
                        if (gLabels[i].type == LABEL_THUMB_CODE)
                        {
                            int tmp_cnt;
                            cs_insn * tmp;
                            printf("\t.hword 0x%04x\n", hword_at(addr));
                            addr += 2;
                            if (insn[j].size == 2) continue;
                            tmp_cnt = cs_disasm(sCapstone, gInputFileBuffer + addr - ROM_LOAD_ADDR, 2, addr, 0, &tmp);
                            assert(tmp_cnt == 1);
                            free(insn[j].detail);
                            insn[j] = *tmp;
                            free(tmp);
                            goto no_inc;
                        }
                        else
                        {
                            printf("\t.word 0x%08x\n", word_at(addr));
                            addr += 4;
                            continue;
                        }
                    }
                    print_insn(&insn[j], addr, gLabels[i].type);
                    addr += insn[j].size;
                }
                cs_free(insn, count);

                // align pool if it comes next
                if (i + 1 < gLabelsCount && gLabels[i + 1].type == LABEL_POOL)
                {
                    const uint8_t zeros[3] = {0};
                    int diff = gLabels[i + 1].addr - addr;
                    if (diff == 0
                     || (diff > 0 && diff < 4 && memcmp(gInputFileBuffer + addr - ROM_LOAD_ADDR, zeros, diff) == 0))
                    {
                        puts("\t.align 2, 0");
                        addr += diff;
                    }
                }
            }
            break;
        case LABEL_POOL:
            {
                uint32_t value = word_at(addr);
                const struct Label *label_p;

                if (value & 3 && value > ROM_LOAD_ADDR && value - ROM_LOAD_ADDR - 1 < gInputFileBufferSize) // possibly thumb function
                {
                    if (label_p = lookup_label(value & ~1), label_p != NULL)
                    {
                        if (label_p->branchType == BRANCH_TYPE_BL && label_p->type == LABEL_THUMB_CODE)
                        {
                            if (label_p->name != NULL)
                                printf("_%08x: .4byte %s\n", addr, label_p->name);
                            else
                                printf("_%08x: .4byte func_%08x\n", addr, value & ~1);
                            addr += 4;
                            break;
                        }
                    }
                }
                label_p = lookup_label(value);
                if (label_p != NULL)
                {
                    if (label_p->type != LABEL_THUMB_CODE)
                    {
                        if (label_p->name != NULL)
                            printf("_%08x: .4byte %s\n", addr, label_p->name);
                        else if (label_p->branchType == BRANCH_TYPE_BL)
                            printf("_%08x: .4byte func_%08x\n", addr, value);
                        else // normal label
                            printf("_%08x: .4byte _%08x\n", addr, value);
                        addr += 4;
                        break;
                    }
                }
                printf("_%08x: .4byte 0x%08x\n", addr, value);
                addr += 4;
            }
            break;
        case LABEL_JUMP_TABLE:
            {
                uint32_t end = addr + gLabels[i].size;
                int caseNum = 0;

                printf("_%08x: @ jump table\n", addr);
                while (addr < end)
                {
                    uint32_t word = word_at(addr);
                    
                    if (word > ROM_LOAD_ADDR && word - ROM_LOAD_ADDR < gInputFileBufferSize)
                        printf("\t.4byte _%08x @ case %i\n", word, caseNum);
                    else
                        printf("\t.4byte 0x%08x @ case %i\n", word, caseNum);
                    caseNum++;
                    addr += 4;
                }
            }
            break;
        }

        i++;
        if (i >= gLabelsCount)
            break;
        nextAddr = gLabels[i].addr;
        assert(addr <= nextAddr);

        if (nextAddr <= ROM_LOAD_ADDR + gInputFileBufferSize) // prevent out-of-bound read
            print_gap(addr, nextAddr);
        addr = nextAddr;
    }
}

static void free_labels(void)
{
    int i, j;

    for (i = 0; i < gLabelsCount; ++i)
    {
        if (gLabels[i].name) free(gLabels[i].name);
        for (j = 0; j < gLabels[i].depCount && gLabels[i].deps[j]; ++j)
            if (gLabels[i].deps[j] != &sInvalidDepNode)
                rec_free_dep_nodes(gLabels[i].deps[j]);
    }
}

void disasm_disassemble(void)
{
    // initialize capstone
    if (cs_open(CS_ARCH_ARM, CS_MODE_ARM, &sCapstone) != CS_ERR_OK)
    {
        puts("cs_open failed");
        return;
    }
    cs_option(sCapstone, CS_OPT_DETAIL, CS_OPT_ON);

    if (!gStandaloneFlag)
    {
        // entry point
        disasm_add_label(ROM_LOAD_ADDR, LABEL_ARM_CODE, NULL);
    }

    if (!gLabelsCount)
        fatal_error("you need to at least provide one code label in the cfg to startwith. ");
    analyze();
    print_disassembly();
    free_labels();
    free(gLabels);
}
