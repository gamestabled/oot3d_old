extern "C" {
#include "z_en_skjneedle.hpp"

#define FLAGS 0x00000205

void EnSkjneedle_Init(Actor* actor, GameState* state);
void EnSkjneedle_Destroy(Actor* actor, GameState* state);
void EnSkjneedle_Update(Actor* actor, GameState* state);
void EnSkjneedle_Draw(Actor* actor, GameState* state);

/*
ActorInit En_Skjneedle_InitVars = {
    ACTOR_EN_SKJNEEDLE,
    ACTORCAT_ENEMY,
    FLAGS,
    OBJECT_SKJ,
    sizeof(EnSkjneedle),
    (ActorFunc)EnSkjneedle_Init,
    (ActorFunc)EnSkjneedle_Destroy,
    (ActorFunc)EnSkjneedle_Update,
    (ActorFunc)EnSkjneedle_Draw,
};
*/

#pragma GLOBAL_ASM("binary/EnSkjneedle_Init.o")

#pragma GLOBAL_ASM("binary/EnSkjneedle_Destroy.o")

#pragma GLOBAL_ASM("binary/EnSkjneedle_Update.o")

#pragma GLOBAL_ASM("binary/EnSkjneedle_Draw.o")
}
