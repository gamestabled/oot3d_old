extern "C" {
#include "z_en_gm.hpp"

#define FLAGS 0x00000019

void EnGm_Init(Actor* actor, GameState* state);
void EnGm_Destroy(Actor* actor, GameState* state);
void EnGm_Update(Actor* actor, GameState* state);

/*
ActorInit En_Gm_InitVars = {
    ACTOR_EN_GM,
    ACTORCAT_NPC,
    FLAGS,
    OBJECT_GM,
    sizeof(EnGm),
    (ActorFunc)EnGm_Init,
    (ActorFunc)EnGm_Destroy,
    (ActorFunc)EnGm_Update,
    (ActorFunc)NULL,
};
*/

GLOBAL_ASM("binary/EnGm_Init.o")

GLOBAL_ASM("binary/EnGm_Destroy.o")

GLOBAL_ASM("binary/EnGm_Update.o")
}
