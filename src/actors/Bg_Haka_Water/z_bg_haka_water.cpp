extern "C" {
#include "z_bg_haka_water.hpp"

#define FLAGS 0x80400030

void BgHakaWater_Init(Actor* actor, GameState* state);
void BgHakaWater_Destroy(Actor* actor, GameState* state);
void BgHakaWater_Update(Actor* actor, GameState* state);
void BgHakaWater_Draw(Actor* actor, GameState* state);

/*
ActorInit Bg_Haka_Water_InitVars = {
    ACTOR_BG_HAKA_WATER,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_HAKACH_OBJECTS,
    sizeof(BgHakaWater),
    (ActorFunc)BgHakaWater_Init,
    (ActorFunc)BgHakaWater_Destroy,
    (ActorFunc)BgHakaWater_Update,
    (ActorFunc)BgHakaWater_Draw,
};
*/

GLOBAL_ASM("binary/BgHakaWater_Init.o")

GLOBAL_ASM("binary/BgHakaWater_Destroy.o")

GLOBAL_ASM("binary/BgHakaWater_Update.o")

GLOBAL_ASM("binary/BgHakaWater_Draw.o")
}
