extern "C" {
#include "z_en_mm2.hpp"

#define FLAGS 0x00000019

void EnMm2_Init(Actor* actor, GameState* state);
void EnMm2_Destroy(Actor* actor, GameState* state);
void EnMm2_Update(Actor* actor, GameState* state);
void EnMm2_Draw(Actor* actor, GameState* state);

/*
ActorInit En_Mm2_InitVars = {
    ACTOR_EN_MM2,
    ACTORCAT_NPC,
    FLAGS,
    OBJECT_MM,
    sizeof(EnMm2),
    (ActorFunc)EnMm2_Init,
    (ActorFunc)EnMm2_Destroy,
    (ActorFunc)EnMm2_Update,
    (ActorFunc)EnMm2_Draw,
};
*/

#pragma GLOBAL_ASM("binary/EnMm2_Init.o")

#pragma GLOBAL_ASM("binary/EnMm2_Destroy.o")

#pragma GLOBAL_ASM("binary/EnMm2_Update.o")

#pragma GLOBAL_ASM("binary/EnMm2_Draw.o")
}
