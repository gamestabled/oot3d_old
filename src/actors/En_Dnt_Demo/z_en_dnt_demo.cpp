extern "C" {
#include "z_en_dnt_demo.hpp"

#define FLAGS 0x00000000

void EnDntDemo_Init(Actor* actor, GameState* state);
void EnDntDemo_Destroy(Actor* actor, GameState* state);
void EnDntDemo_Update(Actor* actor, GameState* state);

/*
ActorInit En_Dnt_Demo_InitVars = {
    ACTOR_EN_DNT_DEMO,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(EnDntDemo),
    (ActorFunc)EnDntDemo_Init,
    (ActorFunc)EnDntDemo_Destroy,
    (ActorFunc)EnDntDemo_Update,
    (ActorFunc)NULL,
};
*/
}
