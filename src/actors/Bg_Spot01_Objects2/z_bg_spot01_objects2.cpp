extern "C" {
#include "z_bg_spot01_objects2.hpp"

#define FLAGS 0x00400010

void BgSpot01Objects2_Init(Actor* actor, GameState* state);
void BgSpot01Objects2_Destroy(Actor* actor, GameState* state);
void BgSpot01Objects2_Update(Actor* actor, GameState* state);

GLOBAL_ASM("binary/z_Bg_Spot01_Objects2.data.o")

/*
ActorInit Bg_Spot01_Objects2_InitVars = {
    ACTOR_BG_SPOT01_OBJECTS2,
    ACTORCAT_BG,
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(BgSpot01Objects2),
    (ActorFunc)BgSpot01Objects2_Init,
    (ActorFunc)BgSpot01Objects2_Destroy,
    (ActorFunc)BgSpot01Objects2_Update,
    NULL,
};
*/

GLOBAL_ASM("binary/BgSpot01Objects2_Init.o")

GLOBAL_ASM("binary/BgSpot01Objects2_Destroy.o")

GLOBAL_ASM("binary/BgSpot01Objects2_Update.o")
}
