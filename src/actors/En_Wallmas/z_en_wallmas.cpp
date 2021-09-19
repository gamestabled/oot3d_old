extern "C" {
#include "z_en_wallmas.hpp"

#define FLAGS 0x00000035

void EnWallmas_Init(Actor* actor, GameState* state);
void EnWallmas_Destroy(Actor* actor, GameState* state);
void EnWallmas_Update(Actor* actor, GameState* state);
void EnWallmas_Draw(Actor* actor, GameState* state);

/*
ActorInit En_Wallmas_InitVars = {
    ACTOR_EN_WALLMAS,
    ACTORCAT_ENEMY,
    FLAGS,
    OBJECT_WALLMASTER,
    sizeof(EnWallmas),
    (ActorFunc)EnWallmas_Init,
    (ActorFunc)EnWallmas_Destroy,
    (ActorFunc)EnWallmas_Update,
    (ActorFunc)EnWallmas_Draw,
};
*/

#pragma GLOBAL_ASM("binary/EnWallmas_Init.o")

#pragma GLOBAL_ASM("binary/EnWallmas_Destroy.o")

#pragma GLOBAL_ASM("binary/EnWallmas_Update.o")

#pragma GLOBAL_ASM("binary/EnWallmas_Draw.o")
}
