extern "C" {
#include "z_en_dha.hpp"

#define FLAGS 0x00000015

void EnDha_Init(Actor* actor, GameState* state);
void EnDha_Destroy(Actor* actor, GameState* state);
void EnDha_Update(Actor* actor, GameState* state);
void EnDha_Draw(Actor* actor, GameState* state);

/*
ActorInit En_Dha_InitVars = {
    ACTOR_EN_DHA,
    ACTORCAT_ENEMY,
    FLAGS,
    OBJECT_DH,
    sizeof(EnDha),
    (ActorFunc)EnDha_Init,
    (ActorFunc)EnDha_Destroy,
    (ActorFunc)EnDha_Update,
    (ActorFunc)EnDha_Draw,
};
*/

#pragma GLOBAL_ASM("binary/EnDha_Init.o")

#pragma GLOBAL_ASM("binary/EnDha_Destroy.o")

#pragma GLOBAL_ASM("binary/EnDha_Update.o")

#pragma GLOBAL_ASM("binary/EnDha_Draw.o")
}
