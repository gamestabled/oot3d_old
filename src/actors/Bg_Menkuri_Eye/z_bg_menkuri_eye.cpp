extern "C" {
#include "z_bg_menkuri_eye.hpp"

#define FLAGS 0x80400020

void BgMenkuriEye_Init(Actor* actor, GameState* state);
void BgMenkuriEye_Destroy(Actor* actor, GameState* state);
void BgMenkuriEye_Update(Actor* actor, GameState* state);
void BgMenkuriEye_Draw(Actor* actor, GameState* state);

GLOBAL_ASM("binary/z_Bg_Menkuri_Eye.data.o")

ActorInit Bg_Menkuri_Eye_InitVars = {
    ACTOR_BG_MENKURI_EYE,
    ACTORCAT_BG,
    FLAGS,
    OBJECT_MENKURI_OBJECTS,
    sizeof(BgMenkuriEye),
    (ActorFunc)BgMenkuriEye_Init,
    (ActorFunc)BgMenkuriEye_Destroy,
    (ActorFunc)BgMenkuriEye_Update,
    (ActorFunc)BgMenkuriEye_Draw,
};

GLOBAL_ASM("binary/BgMenkuriEye_Init.o")

GLOBAL_ASM("binary/BgMenkuriEye_Destroy.o")

GLOBAL_ASM("binary/BgMenkuriEye_Update.o")

GLOBAL_ASM("binary/BgMenkuriEye_Draw.o")
}
