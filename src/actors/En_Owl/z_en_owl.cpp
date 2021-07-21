extern "C" {
#include "z_en_owl.hpp"

#define FLAGS 0x00000019

void EnOwl_Init(Actor* actor, GameState* state);
void EnOwl_Destroy(Actor* actor, GameState* state);
void EnOwl_Update(Actor* actor, GameState* state);
void EnOwl_Draw(Actor* actor, GameState* state);

/*
ActorInit En_Owl_InitVars = {
    ACTOR_EN_OWL,
    ACTORCAT_NPC,
    FLAGS,
    OBJECT_OWL,
    sizeof(EnOwl),
    (ActorFunc)EnOwl_Init,
    (ActorFunc)EnOwl_Destroy,
    (ActorFunc)EnOwl_Update,
    (ActorFunc)EnOwl_Draw,
};
*/
}
