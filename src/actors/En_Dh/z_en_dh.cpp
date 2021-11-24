extern "C" {
#include "z_en_dh.hpp"

#define FLAGS 0x00000415

void EnDh_Init(Actor* actor, GameState* state);
void EnDh_Destroy(Actor* actor, GameState* state);
void EnDh_Update(Actor* actor, GameState* state);
void EnDh_Draw(Actor* actor, GameState* state);

/*
ActorInit En_Dh_InitVars = {
    ACTOR_EN_DH,
    ACTORCAT_ENEMY,
    FLAGS,
    OBJECT_DH,
    sizeof(EnDh),
    (ActorFunc)EnDh_Init,
    (ActorFunc)EnDh_Destroy,
    (ActorFunc)EnDh_Update,
    (ActorFunc)EnDh_Draw,
};
*/

GLOBAL_ASM("binary/EnDh_Init.o")

GLOBAL_ASM("binary/EnDh_Destroy.o")

GLOBAL_ASM("binary/EnDh_Update.o")

GLOBAL_ASM("binary/EnDh_Draw.o")
}
