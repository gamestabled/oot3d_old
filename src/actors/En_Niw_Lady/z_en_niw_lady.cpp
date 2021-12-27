extern "C" {
#include "z_en_niw_lady.hpp"

#define FLAGS 0x00000019

void EnNiwLady_Init(Actor* actor, GameState* state);
void EnNiwLady_Destroy(Actor* actor, GameState* state);
void EnNiwLady_Update(Actor* actor, GameState* state);

GLOBAL_ASM("binary/z_En_Niw_Lady.data.o")

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
    NULL,
};
*/

GLOBAL_ASM("binary/EnNiwLady_Init.o")

GLOBAL_ASM("binary/EnNiwLady_Destroy.o")

GLOBAL_ASM("binary/EnNiwLady_Update.o")
}
