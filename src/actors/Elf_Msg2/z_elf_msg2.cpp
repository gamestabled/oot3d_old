extern "C" {
#include "z_elf_msg2.hpp"

#define FLAGS 0x00000010

void ElfMsg2_Init(Actor* actor, GameState* state);
void ElfMsg2_Destroy(Actor* actor, GameState* state);
void ElfMsg2_Update(Actor* actor, GameState* state);

GLOBAL_ASM("binary/z_Elf_Msg2.data.o")

ActorInit Elf_Msg2_InitVars = {
    ACTOR_ELF_MSG2,
    ACTORCAT_BG,
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(ElfMsg2),
    (ActorFunc)ElfMsg2_Init,
    (ActorFunc)ElfMsg2_Destroy,
    (ActorFunc)ElfMsg2_Update,
    NULL,
};

GLOBAL_ASM("binary/ElfMsg2_Init.o")

GLOBAL_ASM("binary/ElfMsg2_Destroy.o")

GLOBAL_ASM("binary/ElfMsg2_Update.o")
}
