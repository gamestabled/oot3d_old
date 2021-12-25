extern "C" {
#include "z_en_kakasi3.hpp"

#define FLAGS 0x02000009

void EnKakasi3_Init(Actor* actor, GameState* state);
void EnKakasi3_Destroy(Actor* actor, GameState* state);
void EnKakasi3_Update(Actor* actor, GameState* state);
void EnKakasi3_Draw(Actor* actor, GameState* state);

GLOBAL_ASM("binary/z_En_Kakasi3.data.o")

/*
ActorInit En_Kakasi3_InitVars = {
    ACTOR_EN_KAKASI3,
    ACTORCAT_NPC,
    FLAGS,
    OBJECT_KA,
    sizeof(EnKakasi3),
    (ActorFunc)EnKakasi3_Init,
    (ActorFunc)EnKakasi3_Destroy,
    (ActorFunc)EnKakasi3_Update,
    (ActorFunc)EnKakasi3_Draw,
};
*/

GLOBAL_ASM("binary/EnKakasi3_Init.o")

GLOBAL_ASM("binary/EnKakasi3_Destroy.o")

GLOBAL_ASM("binary/EnKakasi3_Update.o")

GLOBAL_ASM("binary/EnKakasi3_Draw.o")
}
