extern "C" {
#include "z_bg_spot01_idohashira.hpp"

#define FLAGS 0x80400010

void BgSpot01Idohashira_Init(Actor* actor, GameState* state);
void BgSpot01Idohashira_Destroy(Actor* actor, GameState* state);
void BgSpot01Idohashira_Update(Actor* actor, GameState* state);
void BgSpot01Idohashira_Draw(Actor* actor, GameState* state);

/*
ActorInit Bg_Spot01_Idohashira_InitVars = {
    ACTOR_BG_SPOT01_IDOHASHIRA,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_SPOT01_OBJECTS,
    sizeof(BgSpot01Idohashira),
    (ActorFunc)BgSpot01Idohashira_Init,
    (ActorFunc)BgSpot01Idohashira_Destroy,
    (ActorFunc)BgSpot01Idohashira_Update,
    (ActorFunc)BgSpot01Idohashira_Draw,
};
*/

#pragma GLOBAL_ASM("binary/BgSpot01Idohashira_Init.o")

#pragma GLOBAL_ASM("binary/BgSpot01Idohashira_Destroy.o")

#pragma GLOBAL_ASM("binary/BgSpot01Idohashira_Update.o")

#pragma GLOBAL_ASM("binary/BgSpot01Idohashira_Draw.o")
}
