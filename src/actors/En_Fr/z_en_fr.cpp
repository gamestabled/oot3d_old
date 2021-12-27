extern "C" {
#include "z_en_fr.hpp"

#define FLAGS 0x02000019

void EnFr_Init(Actor* actor, GameState* state);
void EnFr_Destroy(Actor* actor, GameState* state);
void EnFr_Update(Actor* actor, GameState* state);

GLOBAL_ASM("binary/z_En_Fr.data.o")

/*
ActorInit En_Fr_InitVars = {
    ACTOR_EN_FR,
    ACTORCAT_NPC,
    FLAGS,
    OBJECT_FR,
    sizeof(EnFr),
    (ActorFunc)EnFr_Init,
    (ActorFunc)EnFr_Destroy,
    (ActorFunc)EnFr_Update,
    NULL,
};
*/

GLOBAL_ASM("binary/EnFr_Init.o")

GLOBAL_ASM("binary/EnFr_Destroy.o")

GLOBAL_ASM("binary/EnFr_Update.o")
}
