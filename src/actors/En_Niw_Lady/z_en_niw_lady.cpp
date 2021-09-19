extern "C" {
#include "z_en_niw_lady.hpp"

#define FLAGS 0x00000019

void EnNiwLady_Init(Actor* actor, GameState* state);
void EnNiwLady_Destroy(Actor* actor, GameState* state);
void EnNiwLady_Update(Actor* actor, GameState* state);

/*
ActorInit En_Niw_Lady_InitVars = {
    ACTOR_EN_NIW_LADY,
    ACTORCAT_NPC,
    FLAGS,
    OBJECT_ANE,
    sizeof(EnNiwLady),
    (ActorFunc)EnNiwLady_Init,
    (ActorFunc)EnNiwLady_Destroy,
    (ActorFunc)EnNiwLady_Update,
    (ActorFunc)NULL,
};
*/

#pragma GLOBAL_ASM("binary/EnNiwLady_Init.o")

#pragma GLOBAL_ASM("binary/EnNiwLady_Destroy.o")

#pragma GLOBAL_ASM("binary/EnNiwLady_Update.o")
}
