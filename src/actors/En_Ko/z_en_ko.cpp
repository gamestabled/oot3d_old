extern "C" {
#include "z_en_ko.hpp"

#define FLAGS 0x00000019

void EnKo_Init(Actor* actor, GameState* state);
void EnKo_Destroy(Actor* actor, GameState* state);
void EnKo_Update(Actor* actor, GameState* state);
void EnKo_Draw(Actor* actor, GameState* state);

/*
ActorInit En_Ko_InitVars = {
    ACTOR_EN_KO,
    ACTORCAT_NPC,
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(EnKo),
    (ActorFunc)EnKo_Init,
    (ActorFunc)EnKo_Destroy,
    (ActorFunc)EnKo_Update,
    (ActorFunc)EnKo_Draw,
};
*/
}
