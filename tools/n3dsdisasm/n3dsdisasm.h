#include <stdbool.h>

enum BranchType
{
    BRANCH_TYPE_UNKNOWN,
    BRANCH_TYPE_B,
    BRANCH_TYPE_BL,
};

enum LabelType
{
    LABEL_ARM_CODE,
    LABEL_THUMB_CODE,
    LABEL_DATA,
    LABEL_POOL,
    LABEL_JUMP_TABLE,
};

extern uint8_t *gInputFileBuffer;
extern size_t gInputFileBufferSize;
extern uint32_t ROM_LOAD_ADDR;
extern bool gStandaloneFlag;

// disasm.c
int disasm_add_label(uint32_t addr, uint8_t type, char *name);
int disasm_set_branch_type(uint32_t addr, uint32_t type, bool farJump);
void disasm_force_func(int idx);
void disasm_disassemble(void);
int jump_table_create_labels(uint32_t start, int count);
