extern "C" {
#include "z_en_bom_bowl_pit.hpp"

#define FLAGS 0x80000010

void EnBomBowlPit_Init(Actor* actor, GameState* state);
void EnBomBowlPit_Destroy(Actor* actor, GameState* state);
void EnBomBowlPit_Update(Actor* actor, GameState* state);

/*
ActorInit En_Bom_Bowl_Pit_InitVars = {
    ACTOR_EN_BOM_BOWL_PIT,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(EnBomBowlPit),
    (ActorFunc)EnBomBowlPit_Init,
    (ActorFunc)EnBomBowlPit_Destroy,
    (ActorFunc)EnBomBowlPit_Update,
    (ActorFunc)NULL,
};
*/
}
