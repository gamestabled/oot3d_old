extern "C" {
#include "z_en_kz.hpp"

#define FLAGS 0x00000009

void EnKz_Init(Actor* actor, GameState* state);
void EnKz_Destroy(Actor* actor, GameState* state);
void EnKz_Update(Actor* actor, GameState* state);
void EnKz_Draw(Actor* actor, GameState* state);

/*
ActorInit En_Kz_InitVars = {
    ACTOR_EN_KZ,
    ACTORCAT_NPC,
    FLAGS,
    OBJECT_KZ,
    sizeof(EnKz),
    (ActorFunc)EnKz_Init,
    (ActorFunc)EnKz_Destroy,
    (ActorFunc)EnKz_Update,
    (ActorFunc)EnKz_Draw,
};
*/

#pragma GLOBAL_ASM("binary/EnKz_Init.o")

#pragma GLOBAL_ASM("binary/EnKz_Destroy.o")

#pragma GLOBAL_ASM("binary/EnKz_Update.o")

#pragma GLOBAL_ASM("binary/EnKz_Draw.o")
}
