extern "C" {
#include "z_en_horse_normal.hpp"

#define FLAGS 0x00000000

void EnHorseNormal_Init(Actor* actor, GameState* state);
void EnHorseNormal_Destroy(Actor* actor, GameState* state);
void EnHorseNormal_Update(Actor* actor, GameState* state);
void EnHorseNormal_Draw(Actor* actor, GameState* state);

/*
ActorInit En_Horse_Normal_InitVars = {
    ACTOR_EN_HORSE_NORMAL,
    ACTORCAT_BG,
    FLAGS,
    OBJECT_HORSE_NORMAL,
    sizeof(EnHorseNormal),
    (ActorFunc)EnHorseNormal_Init,
    (ActorFunc)EnHorseNormal_Destroy,
    (ActorFunc)EnHorseNormal_Update,
    (ActorFunc)EnHorseNormal_Draw,
};
*/

GLOBAL_ASM("binary/EnHorseNormal_Init.o")

GLOBAL_ASM("binary/EnHorseNormal_Destroy.o")

GLOBAL_ASM("binary/EnHorseNormal_Update.o")

GLOBAL_ASM("binary/EnHorseNormal_Draw.o")
}
