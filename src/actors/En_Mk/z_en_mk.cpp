extern "C" {
#include "z_en_mk.hpp"

#define FLAGS 0x00000019

void EnMk_Init(Actor* actor, GameState* state);
void EnMk_Destroy(Actor* actor, GameState* state);
void EnMk_Update(Actor* actor, GameState* state);
void EnMk_Draw(Actor* actor, GameState* state);

/*
ActorInit En_Mk_InitVars = {
    ACTOR_EN_MK,
    ACTORCAT_NPC,
    FLAGS,
    OBJECT_MK,
    sizeof(EnMk),
    (ActorFunc)EnMk_Init,
    (ActorFunc)EnMk_Destroy,
    (ActorFunc)EnMk_Update,
    (ActorFunc)EnMk_Draw,
};
*/

#pragma GLOBAL_ASM("binary/EnMk_Init.o")

#pragma GLOBAL_ASM("binary/EnMk_Destroy.o")

#pragma GLOBAL_ASM("binary/EnMk_Update.o")

#pragma GLOBAL_ASM("binary/EnMk_Draw.o")
}
