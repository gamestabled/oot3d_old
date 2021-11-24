extern "C" {
#include "z_en_ds.hpp"

#define FLAGS 0x00000009

void EnDs_Init(Actor* actor, GameState* state);
void EnDs_Destroy(Actor* actor, GameState* state);
void EnDs_Update(Actor* actor, GameState* state);
void EnDs_Draw(Actor* actor, GameState* state);

/*
ActorInit En_Ds_InitVars = {
    ACTOR_EN_DS,
    ACTORCAT_NPC,
    FLAGS,
    OBJECT_DS,
    sizeof(EnDs),
    (ActorFunc)EnDs_Init,
    (ActorFunc)EnDs_Destroy,
    (ActorFunc)EnDs_Update,
    (ActorFunc)EnDs_Draw,
};
*/

GLOBAL_ASM("binary/EnDs_Init.o")

GLOBAL_ASM("binary/EnDs_Destroy.o")

GLOBAL_ASM("binary/EnDs_Update.o")

GLOBAL_ASM("binary/EnDs_Draw.o")
}
