extern "C" {
#include "z_en_du.hpp"

#define FLAGS 0x02000009

void EnDu_Init(Actor* actor, GameState* state);
void EnDu_Destroy(Actor* actor, GameState* state);
void EnDu_Update(Actor* actor, GameState* state);
void EnDu_Draw(Actor* actor, GameState* state);

/*
ActorInit En_Du_InitVars = {
    ACTOR_EN_DU,
    ACTORCAT_NPC,
    FLAGS,
    OBJECT_DU,
    sizeof(EnDu),
    (ActorFunc)EnDu_Init,
    (ActorFunc)EnDu_Destroy,
    (ActorFunc)EnDu_Update,
    (ActorFunc)EnDu_Draw,
};
*/

#pragma GLOBAL_ASM("binary/EnDu_Init.o")

#pragma GLOBAL_ASM("binary/EnDu_Destroy.o")

#pragma GLOBAL_ASM("binary/EnDu_Update.o")

#pragma GLOBAL_ASM("binary/EnDu_Draw.o")
}
