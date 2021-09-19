extern "C" {
#include "z_en_elf.hpp"

#define FLAGS 0x02000030

void EnElf_Init(Actor* actor, GameState* state);
void EnElf_Destroy(Actor* actor, GameState* state);
void EnElf_Update(Actor* actor, GameState* state);
void EnElf_Draw(Actor* actor, GameState* state);

/*
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
*/

#pragma GLOBAL_ASM("binary/EnElf_Init.o")

#pragma GLOBAL_ASM("binary/EnElf_Destroy.o")

#pragma GLOBAL_ASM("binary/EnElf_Update.o")

#pragma GLOBAL_ASM("binary/EnElf_Draw.o")
}
