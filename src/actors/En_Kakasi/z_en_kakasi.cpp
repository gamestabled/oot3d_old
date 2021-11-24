extern "C" {
#include "z_en_kakasi.hpp"

#define FLAGS 0x02000009

void EnKakasi_Init(Actor* actor, GameState* state);
void EnKakasi_Destroy(Actor* actor, GameState* state);
void EnKakasi_Update(Actor* actor, GameState* state);
void EnKakasi_Draw(Actor* actor, GameState* state);

/*
ActorInit En_Kakasi_InitVars = {
    ACTOR_EN_KAKASI,
    ACTORCAT_NPC,
    FLAGS,
    OBJECT_KA,
    sizeof(EnKakasi),
    (ActorFunc)EnKakasi_Init,
    (ActorFunc)EnKakasi_Destroy,
    (ActorFunc)EnKakasi_Update,
    (ActorFunc)EnKakasi_Draw,
};
*/

GLOBAL_ASM("binary/EnKakasi_Init.o")

GLOBAL_ASM("binary/EnKakasi_Destroy.o")

GLOBAL_ASM("binary/EnKakasi_Update.o")

GLOBAL_ASM("binary/EnKakasi_Draw.o")
}
