extern "C" {
#include "z_en_kz.hpp"

#define FLAGS 0x00000009

void EnKz_Init(Actor* actor, GameState* state);
void EnKz_Destroy(Actor* actor, GameState* state);
void EnKz_Update(Actor* actor, GameState* state);
void EnKz_Draw(Actor* actor, GameState* state);

GLOBAL_ASM("binary/z_En_Kz.data.o")

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

GLOBAL_ASM("binary/EnKz_Init.o")

GLOBAL_ASM("binary/EnKz_Destroy.o")

GLOBAL_ASM("binary/EnKz_Update.o")

GLOBAL_ASM("binary/EnKz_Draw.o")
}
