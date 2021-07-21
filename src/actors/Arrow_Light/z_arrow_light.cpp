extern "C" {
#include "z_arrow_light.hpp"

#define FLAGS 0x02000010

void ArrowLight_Init(Actor* actor, GameState* state);
void ArrowLight_Destroy(Actor* actor, GameState* state);
void ArrowLight_Update(Actor* actor, GameState* state);
void ArrowLight_Draw(Actor* actor, GameState* state);

/*
ActorInit Arrow_Light_InitVars = {
    ACTOR_ARROW_LIGHT,
    ACTORCAT_ITEMACTION,
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(ArrowLight),
    (ActorFunc)ArrowLight_Init,
    (ActorFunc)ArrowLight_Destroy,
    (ActorFunc)ArrowLight_Update,
    (ActorFunc)ArrowLight_Draw,
};
*/
}
