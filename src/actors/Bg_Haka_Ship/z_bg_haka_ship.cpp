extern "C" {
#include "z_bg_haka_ship.hpp"

#define FLAGS 0x80400030

void BgHakaShip_Init(Actor* actor, GameState* state);
void BgHakaShip_Destroy(Actor* actor, GameState* state);
void BgHakaShip_Update(Actor* actor, GameState* state);
void BgHakaShip_Draw(Actor* actor, GameState* state);

GLOBAL_ASM("binary/z_Bg_Haka_Ship.data.o")

/*
ActorInit Bg_Haka_Ship_InitVars = {
    ACTOR_BG_HAKA_SHIP,
    ACTORCAT_BG,
    FLAGS,
    OBJECT_HAKA_OBJECTS,
    sizeof(BgHakaShip),
    (ActorFunc)BgHakaShip_Init,
    (ActorFunc)BgHakaShip_Destroy,
    (ActorFunc)BgHakaShip_Update,
    (ActorFunc)BgHakaShip_Draw,
};
*/

GLOBAL_ASM("binary/BgHakaShip_Init.o")

GLOBAL_ASM("binary/BgHakaShip_Destroy.o")

GLOBAL_ASM("binary/BgHakaShip_Update.o")

GLOBAL_ASM("binary/BgHakaShip_Draw.o")
}
