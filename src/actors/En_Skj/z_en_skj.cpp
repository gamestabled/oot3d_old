extern "C" {
#include "z_en_skj.hpp"

#define FLAGS 0x02000015

void EnSkj_Init(Actor* actor, GameState* state);
void EnSkj_Destroy(Actor* actor, GameState* state);
void EnSkj_Update(Actor* actor, GameState* state);
void EnSkj_Draw(Actor* actor, GameState* state);

GLOBAL_ASM("binary/z_En_Skj.data.o")

/*
ActorInit En_Skj_InitVars = {
    ACTOR_EN_SKJ,
    ACTORCAT_ENEMY,
    FLAGS,
    OBJECT_SKJ,
    sizeof(EnSkj),
    (ActorFunc)EnSkj_Init,
    (ActorFunc)EnSkj_Destroy,
    (ActorFunc)EnSkj_Update,
    (ActorFunc)EnSkj_Draw,
};
*/

GLOBAL_ASM("binary/EnSkj_Init.o")

GLOBAL_ASM("binary/EnSkj_Destroy.o")

GLOBAL_ASM("binary/EnSkj_Update.o")

GLOBAL_ASM("binary/EnSkj_Draw.o")
}
