extern "C" {
#include "z_bg_ice_shelter.hpp"

#define FLAGS 0x00400010

void BgIceShelter_Init(Actor* actor, GameState* state);
void BgIceShelter_Destroy(Actor* actor, GameState* state);
void BgIceShelter_Update(Actor* actor, GameState* state);
void BgIceShelter_Draw(Actor* actor, GameState* state);

/*
ActorInit Bg_Ice_Shelter_InitVars = {
    ACTOR_BG_ICE_SHELTER,
    ACTORCAT_BG,
    FLAGS,
    OBJECT_ICE_OBJECTS,
    sizeof(BgIceShelter),
    (ActorFunc)BgIceShelter_Init,
    (ActorFunc)BgIceShelter_Destroy,
    (ActorFunc)BgIceShelter_Update,
    (ActorFunc)BgIceShelter_Draw,
};
*/

GLOBAL_ASM("binary/BgIceShelter_Init.o")

GLOBAL_ASM("binary/BgIceShelter_Destroy.o")

GLOBAL_ASM("binary/BgIceShelter_Update.o")

GLOBAL_ASM("binary/BgIceShelter_Draw.o")
}
