extern "C" {
#include "z_en_elf.hpp"

#define FLAGS 0x02000030

void EnElf_Init(Actor* actor, GameState* state);
void EnElf_Destroy(Actor* actor, GameState* state);
void EnElf_Update(Actor* actor, GameState* state);
void EnElf_Draw(Actor* actor, GameState* state);

GLOBAL_ASM("binary/z_En_Elf.data_00522E74.o")
GLOBAL_ASM("binary/z_En_Elf.data_005230C4.o")

ActorInit En_Elf_InitVars = {
    ACTOR_EN_ELF,
    ACTORCAT_ITEMACTION,
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(EnElf),
    (ActorFunc)EnElf_Init,
    (ActorFunc)EnElf_Destroy,
    (ActorFunc)EnElf_Update,
    (ActorFunc)EnElf_Draw,
};

GLOBAL_ASM("binary/EnElf_Init.o")

GLOBAL_ASM("binary/EnElf_Destroy.o")

GLOBAL_ASM("binary/EnElf_Update.o")

GLOBAL_ASM("binary/EnElf_Draw.o")
}
