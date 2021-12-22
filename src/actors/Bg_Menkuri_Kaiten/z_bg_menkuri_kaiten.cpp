extern "C" {
#include "z_bg_menkuri_kaiten.hpp"

#define FLAGS 0x80400030

void BgMenkuriKaiten_Init(Actor* actor, GameState* state);
void BgMenkuriKaiten_Destroy(Actor* actor, GameState* state);
void BgMenkuriKaiten_Update(Actor* actor, GameState* state);
void BgMenkuriKaiten_Draw(Actor* actor, GameState* state);

GLOBAL_ASM("binary/z_Bg_Menkuri_Kaiten.data.o")

/*
ActorInit Bg_Menkuri_Kaiten_InitVars = {
    ACTOR_BG_MENKURI_KAITEN,
    ACTORCAT_BG,
    FLAGS,
    OBJECT_MENKURI_OBJECTS,
    sizeof(BgMenkuriKaiten),
    (ActorFunc)BgMenkuriKaiten_Init,
    (ActorFunc)BgMenkuriKaiten_Destroy,
    (ActorFunc)BgMenkuriKaiten_Update,
    (ActorFunc)BgMenkuriKaiten_Draw,
};
*/

GLOBAL_ASM("binary/BgMenkuriKaiten_Init.o")

GLOBAL_ASM("binary/BgMenkuriKaiten_Destroy.o")

GLOBAL_ASM("binary/BgMenkuriKaiten_Update.o")

GLOBAL_ASM("binary/BgMenkuriKaiten_Draw.o")
}
