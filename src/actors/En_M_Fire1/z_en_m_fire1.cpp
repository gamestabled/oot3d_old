extern "C" {
#include "z_en_m_fire1.hpp"

#define FLAGS 0x00000000

void EnMFire1_Init(Actor* actor, GameState* state);
void EnMFire1_Destroy(Actor* actor, GameState* state);
void EnMFire1_Update(Actor* actor, GameState* state);

/*
ActorInit En_M_Fire1_InitVars = {
    ACTOR_EN_M_FIRE1,
    ACTORCAT_MISC,
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(EnMFire1),
    (ActorFunc)EnMFire1_Init,
    (ActorFunc)EnMFire1_Destroy,
    (ActorFunc)EnMFire1_Update,
    (ActorFunc)NULL,
};
*/

#pragma GLOBAL_ASM("binary/EnMFire1_Init.o")

#pragma GLOBAL_ASM("binary/EnMFire1_Destroy.o")

#pragma GLOBAL_ASM("binary/EnMFire1_Update.o")
}
