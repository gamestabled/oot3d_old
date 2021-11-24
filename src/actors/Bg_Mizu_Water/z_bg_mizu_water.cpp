extern "C" {
#include "z_bg_mizu_water.hpp"

#define FLAGS 0x80400030

void BgMizuWater_Init(Actor* actor, GameState* state);
void BgMizuWater_Destroy(Actor* actor, GameState* state);
void BgMizuWater_Update(Actor* actor, GameState* state);
void BgMizuWater_Draw(Actor* actor, GameState* state);

/*
ActorInit Bg_Mizu_Water_InitVars = {
    ACTOR_BG_MIZU_WATER,
    ACTORCAT_BG,
    FLAGS,
    OBJECT_MIZU_OBJECTS,
    sizeof(BgMizuWater),
    (ActorFunc)BgMizuWater_Init,
    (ActorFunc)BgMizuWater_Destroy,
    (ActorFunc)BgMizuWater_Update,
    (ActorFunc)BgMizuWater_Draw,
};
*/

GLOBAL_ASM("binary/BgMizuWater_Init.o")

GLOBAL_ASM("binary/BgMizuWater_Destroy.o")

GLOBAL_ASM("binary/BgMizuWater_Update.o")

GLOBAL_ASM("binary/BgMizuWater_Draw.o")
}
