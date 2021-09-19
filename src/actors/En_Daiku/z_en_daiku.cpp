extern "C" {
#include "z_en_daiku.hpp"

#define FLAGS 0x00000019

void EnDaiku_Init(Actor* actor, GameState* state);
void EnDaiku_Destroy(Actor* actor, GameState* state);
void EnDaiku_Update(Actor* actor, GameState* state);
void EnDaiku_Draw(Actor* actor, GameState* state);

/*
ActorInit En_Daiku_InitVars = {
    ACTOR_EN_DAIKU,
    ACTORCAT_NPC,
    FLAGS,
    OBJECT_DAIKU,
    sizeof(EnDaiku),
    (ActorFunc)EnDaiku_Init,
    (ActorFunc)EnDaiku_Destroy,
    (ActorFunc)EnDaiku_Update,
    (ActorFunc)EnDaiku_Draw,
};
*/

#pragma GLOBAL_ASM("binary/EnDaiku_Init.o")

#pragma GLOBAL_ASM("binary/EnDaiku_Destroy.o")

#pragma GLOBAL_ASM("binary/EnDaiku_Update.o")

#pragma GLOBAL_ASM("binary/EnDaiku_Draw.o")
}
