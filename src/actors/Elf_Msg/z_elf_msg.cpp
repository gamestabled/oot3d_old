extern "C" {
#include "z_elf_msg.hpp"

#define FLAGS 0x00000010

void ElfMsg_Init(Actor* actor, GameState* state);
void ElfMsg_Destroy(Actor* actor, GameState* state);
void ElfMsg_Update(Actor* actor, GameState* state);
void ElfMsg_Draw(Actor* actor, GameState* state);

/*
ActorInit Elf_Msg_InitVars = {
    ACTOR_ELF_MSG,
    ACTORCAT_ITEMACTION,
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(ElfMsg),
    (ActorFunc)ElfMsg_Init,
    (ActorFunc)ElfMsg_Destroy,
    (ActorFunc)ElfMsg_Update,
    (ActorFunc)ElfMsg_Draw,
};
*/

#pragma GLOBAL_ASM("binary/ElfMsg_Init.o")

#pragma GLOBAL_ASM("binary/ElfMsg_Destroy.o")

#pragma GLOBAL_ASM("binary/ElfMsg_Update.o")

#pragma GLOBAL_ASM("binary/ElfMsg_Draw.o")
}
