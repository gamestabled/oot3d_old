extern "C" {
#include "z_en_dnt_nomal.hpp"

#define FLAGS 0x00000030

void EnDntNomal_Init(Actor* actor, GameState* state);
void EnDntNomal_Destroy(Actor* actor, GameState* state);
void EnDntNomal_Update(Actor* actor, GameState* state);

/*
ActorInit En_Dnt_Nomal_InitVars = {
    ACTOR_EN_DNT_NOMAL,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(EnDntNomal),
    (ActorFunc)EnDntNomal_Init,
    (ActorFunc)EnDntNomal_Destroy,
    (ActorFunc)EnDntNomal_Update,
    (ActorFunc)NULL,
};
*/

#pragma GLOBAL_ASM("binary/EnDntNomal_Init.o")

#pragma GLOBAL_ASM("binary/EnDntNomal_Destroy.o")

#pragma GLOBAL_ASM("binary/EnDntNomal_Update.o")
}
