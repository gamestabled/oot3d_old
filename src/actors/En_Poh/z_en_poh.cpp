extern "C" {
#include "z_en_poh.hpp"

#define FLAGS 0x00001015

void EnPoh_Init(Actor* actor, GameState* state);
void EnPoh_Destroy(Actor* actor, GameState* state);
void EnPoh_Update(Actor* actor, GameState* state);

GLOBAL_ASM("binary/z_En_Poh.data.o")

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

GLOBAL_ASM("binary/EnPoh_Init.o")

GLOBAL_ASM("binary/EnPoh_Destroy.o")

GLOBAL_ASM("binary/EnPoh_Update.o")
}
