extern "C" {
#include "z_en_dnt_nomal.hpp"

#define FLAGS 0x00000030

void EnDntNomal_Init(Actor* actor, GameState* state);
void EnDntNomal_Destroy(Actor* actor, GameState* state);
void EnDntNomal_Update(Actor* actor, GameState* state);

GLOBAL_ASM("binary/z_En_Dnt_Nomal.data.o")

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

GLOBAL_ASM("binary/EnDntNomal_Init.o")

GLOBAL_ASM("binary/EnDntNomal_Destroy.o")

GLOBAL_ASM("binary/EnDntNomal_Update.o")
}
