extern "C" {
#include "z_en_river_sound.hpp"

#define FLAGS 0x20000030

void EnRiverSound_Init(Actor* actor, GameState* state);
void EnRiverSound_Destroy(Actor* actor, GameState* state);
void EnRiverSound_Update(Actor* actor, GameState* state);
void EnRiverSound_Draw(Actor* actor, GameState* state);

GLOBAL_ASM("binary/z_En_River_Sound.data.o")

ActorInit En_River_Sound_InitVars = {
    ACTOR_EN_RIVER_SOUND,
    ACTORCAT_BG,
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(EnRiverSound),
    (ActorFunc)EnRiverSound_Init,
    (ActorFunc)EnRiverSound_Destroy,
    (ActorFunc)EnRiverSound_Update,
    (ActorFunc)EnRiverSound_Draw,
};

GLOBAL_ASM("binary/EnRiverSound_Init.o")

GLOBAL_ASM("binary/EnRiverSound_Destroy.o")

GLOBAL_ASM("binary/EnRiverSound_Update.o")

GLOBAL_ASM("binary/EnRiverSound_Draw.o")
}
