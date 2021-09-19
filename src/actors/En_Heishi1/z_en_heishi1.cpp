extern "C" {
#include "z_en_heishi1.hpp"

#define FLAGS 0x00000010

void EnHeishi1_Init(Actor* actor, GameState* state);
void EnHeishi1_Destroy(Actor* actor, GameState* state);
void EnHeishi1_Update(Actor* actor, GameState* state);
void EnHeishi1_Draw(Actor* actor, GameState* state);

/*
ActorInit En_Heishi1_InitVars = {
    ACTOR_PLAYER,
    ACTORCAT_NPC,
    FLAGS,
    OBJECT_SD,
    sizeof(EnHeishi1),
    (ActorFunc)EnHeishi1_Init,
    (ActorFunc)EnHeishi1_Destroy,
    (ActorFunc)EnHeishi1_Update,
    (ActorFunc)EnHeishi1_Draw,
};
*/

#pragma GLOBAL_ASM("binary/EnHeishi1_Init.o")

#pragma GLOBAL_ASM("binary/EnHeishi1_Destroy.o")

#pragma GLOBAL_ASM("binary/EnHeishi1_Update.o")

#pragma GLOBAL_ASM("binary/EnHeishi1_Draw.o")
}
