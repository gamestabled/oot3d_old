extern "C" {
#include "z_mir_ray.hpp"

#define FLAGS 0x00000030

void MirRay_Init(Actor* actor, GameState* state);
void MirRay_Destroy(Actor* actor, GameState* state);
void MirRay_Update(Actor* actor, GameState* state);
void MirRay_Draw(Actor* actor, GameState* state);

/*
ActorInit Mir_Ray_InitVars = {
    ACTOR_MIR_RAY,
    ACTORCAT_ITEMACTION,
    FLAGS,
    OBJECT_MIR_RAY,
    sizeof(MirRay),
    (ActorFunc)MirRay_Init,
    (ActorFunc)MirRay_Destroy,
    (ActorFunc)MirRay_Update,
    (ActorFunc)MirRay_Draw,
};
*/

#pragma GLOBAL_ASM("binary/MirRay_Init.o")

#pragma GLOBAL_ASM("binary/MirRay_Destroy.o")

#pragma GLOBAL_ASM("binary/MirRay_Update.o")

#pragma GLOBAL_ASM("binary/MirRay_Draw.o")
}
