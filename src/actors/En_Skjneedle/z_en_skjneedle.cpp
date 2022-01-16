extern "C" {
#include "z_en_skjneedle.hpp"

#define FLAGS 0x00000205

void EnSkjneedle_Init(Actor* actor, GameState* state);
void EnSkjneedle_Destroy(Actor* actor, GameState* state);
void EnSkjneedle_Update(Actor* actor, GameState* state);
void EnSkjneedle_Draw(Actor* actor, GameState* state);

GLOBAL_ASM("binary/z_En_Skjneedle.data.o")

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

GLOBAL_ASM("binary/EnSkjneedle_Init.o")

GLOBAL_ASM("binary/EnSkjneedle_Destroy.o")

GLOBAL_ASM("binary/EnSkjneedle_Update.o")

GLOBAL_ASM("binary/EnSkjneedle_Draw.o")
}
