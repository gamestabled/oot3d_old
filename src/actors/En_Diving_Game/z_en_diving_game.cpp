extern "C" {
#include "z_en_diving_game.hpp"

#define FLAGS 0x00000019

void EnDivingGame_Init(Actor* actor, GameState* state);
void EnDivingGame_Destroy(Actor* actor, GameState* state);
void EnDivingGame_Update(Actor* actor, GameState* state);
void EnDivingGame_Draw(Actor* actor, GameState* state);

/*
ActorInit En_Diving_Game_InitVars = {
    ACTOR_EN_DIVING_GAME,
    ACTORCAT_NPC,
    FLAGS,
    OBJECT_ZO,
    sizeof(EnDivingGame),
    (ActorFunc)EnDivingGame_Init,
    (ActorFunc)EnDivingGame_Destroy,
    (ActorFunc)EnDivingGame_Update,
    (ActorFunc)EnDivingGame_Draw,
};
*/

#pragma GLOBAL_ASM("binary/EnDivingGame_Init.o")

#pragma GLOBAL_ASM("binary/EnDivingGame_Destroy.o")

#pragma GLOBAL_ASM("binary/EnDivingGame_Update.o")

#pragma GLOBAL_ASM("binary/EnDivingGame_Draw.o")
}
