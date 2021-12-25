extern "C" {
#include "z_en_heishi4.hpp"

#define FLAGS 0x00000009

void EnHeishi4_Init(Actor* actor, GameState* state);
void EnHeishi4_Destroy(Actor* actor, GameState* state);
void EnHeishi4_Update(Actor* actor, GameState* state);
void EnHeishi4_Draw(Actor* actor, GameState* state);

GLOBAL_ASM("binary/z_En_Heishi4.data.o")

/*
ActorInit En_Heishi4_InitVars = {
    ACTOR_EN_HEISHI4,
    ACTORCAT_NPC,
    FLAGS,
    OBJECT_SD,
    sizeof(EnHeishi4),
    (ActorFunc)EnHeishi4_Init,
    (ActorFunc)EnHeishi4_Destroy,
    (ActorFunc)EnHeishi4_Update,
    (ActorFunc)EnHeishi4_Draw,
};
*/

GLOBAL_ASM("binary/EnHeishi4_Init.o")

GLOBAL_ASM("binary/EnHeishi4_Destroy.o")

GLOBAL_ASM("binary/EnHeishi4_Update.o")

GLOBAL_ASM("binary/EnHeishi4_Draw.o")
}
