extern "C" {
#include "z_en_poh.hpp"

#define FLAGS 0x00001015

void EnPoh_Init(Actor* actor, GameState* state);
void EnPoh_Destroy(Actor* actor, GameState* state);
void EnPoh_Update(Actor* actor, GameState* state);

/*
ActorInit En_Poh_InitVars = {
    ACTOR_EN_POH,
    ACTORCAT_ENEMY,
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(EnPoh),
    (ActorFunc)EnPoh_Init,
    (ActorFunc)EnPoh_Destroy,
    (ActorFunc)EnPoh_Update,
    (ActorFunc)NULL,
};
*/
}
