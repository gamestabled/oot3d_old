extern "C" {
#include "z_arrow_ice.hpp"

#define FLAGS 0x02000010

void ArrowIce_Init(Actor* actor, GameState* state);
void ArrowIce_Destroy(Actor* actor, GameState* state);
void ArrowIce_Update(Actor* actor, GameState* state);
void ArrowIce_Draw(Actor* actor, GameState* state);

/*
ActorInit Arrow_Ice_InitVars = {
    ACTOR_ARROW_ICE,
    ACTORCAT_ITEMACTION,
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(ArrowIce),
    (ActorFunc)ArrowIce_Init,
    (ActorFunc)ArrowIce_Destroy,
    (ActorFunc)ArrowIce_Update,
    (ActorFunc)ArrowIce_Draw,
};
*/
}
