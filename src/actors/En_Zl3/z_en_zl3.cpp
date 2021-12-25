extern "C" {
#include "z_en_zl3.hpp"

#define FLAGS 0x00000010

void EnZl3_Init(Actor* actor, GameState* state);
void EnZl3_Destroy(Actor* actor, GameState* state);
void EnZl3_Update(Actor* actor, GameState* state);
void EnZl3_Draw(Actor* actor, GameState* state);

GLOBAL_ASM("binary/z_En_Zl3.data.o")

/*
ActorInit En_Zl3_InitVars = {
    ACTOR_EN_ZL3,
    ACTORCAT_NPC,
    FLAGS,
    OBJECT_ZL2,
    sizeof(EnZl3),
    (ActorFunc)EnZl3_Init,
    (ActorFunc)EnZl3_Destroy,
    (ActorFunc)EnZl3_Update,
    (ActorFunc)EnZl3_Draw,
};
*/

GLOBAL_ASM("binary/EnZl3_Init.o")

GLOBAL_ASM("binary/EnZl3_Destroy.o")

GLOBAL_ASM("binary/EnZl3_Update.o")

GLOBAL_ASM("binary/EnZl3_Draw.o")
}
