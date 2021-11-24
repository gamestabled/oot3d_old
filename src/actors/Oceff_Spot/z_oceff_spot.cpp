extern "C" {
#include "z_oceff_spot.hpp"

#define FLAGS 0x02000010

void OceffSpot_Init(Actor* actor, GameState* state);
void OceffSpot_Destroy(Actor* actor, GameState* state);
void OceffSpot_Update(Actor* actor, GameState* state);
void OceffSpot_Draw(Actor* actor, GameState* state);

/*
ActorInit Oceff_Spot_InitVars = {
    ACTOR_OCEFF_SPOT,
    ACTORCAT_ITEMACTION,
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(OceffSpot),
    (ActorFunc)OceffSpot_Init,
    (ActorFunc)OceffSpot_Destroy,
    (ActorFunc)OceffSpot_Update,
    (ActorFunc)OceffSpot_Draw,
};
*/

GLOBAL_ASM("binary/OceffSpot_Init.o")

GLOBAL_ASM("binary/OceffSpot_Destroy.o")

GLOBAL_ASM("binary/OceffSpot_Update.o")

GLOBAL_ASM("binary/OceffSpot_Draw.o")
}
