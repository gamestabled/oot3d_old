extern "C" {
#include "z_en_wallmas.hpp"

#define FLAGS 0x00000035

void EnWallmas_Init(Actor* actor, GameState* state);
void EnWallmas_Destroy(Actor* actor, GameState* state);
void EnWallmas_Update(Actor* actor, GameState* state);
void EnWallmas_Draw(Actor* actor, GameState* state);

GLOBAL_ASM("binary/z_En_Wallmas.data.o")

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

GLOBAL_ASM("binary/EnWallmas_Init.o")

GLOBAL_ASM("binary/EnWallmas_Destroy.o")

GLOBAL_ASM("binary/EnWallmas_Update.o")

GLOBAL_ASM("binary/EnWallmas_Draw.o")
}
