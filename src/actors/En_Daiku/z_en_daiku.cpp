extern "C" {
#include "z_en_daiku.hpp"

#define FLAGS 0x00000019

void EnDaiku_Init(Actor* actor, GameState* state);
void EnDaiku_Destroy(Actor* actor, GameState* state);
void EnDaiku_Update(Actor* actor, GameState* state);
void EnDaiku_Draw(Actor* actor, GameState* state);

GLOBAL_ASM("binary/z_En_Daiku.data.o")

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

GLOBAL_ASM("binary/EnDaiku_Init.o")

GLOBAL_ASM("binary/EnDaiku_Destroy.o")

GLOBAL_ASM("binary/EnDaiku_Update.o")

GLOBAL_ASM("binary/EnDaiku_Draw.o")
}
