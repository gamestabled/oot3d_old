extern "C" {
#include "z_bg_menkuri_nisekabe.hpp"

#define FLAGS 0x80400030

void BgMenkuriNisekabe_Init(Actor* actor, GameState* state);
void BgMenkuriNisekabe_Destroy(Actor* actor, GameState* state);
void BgMenkuriNisekabe_Update(Actor* actor, GameState* state);
void BgMenkuriNisekabe_Draw(Actor* actor, GameState* state);

/*
ActorInit Bg_Menkuri_Nisekabe_InitVars = {
    ACTOR_BG_MENKURI_NISEKABE,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_MENKURI_OBJECTS,
    sizeof(BgMenkuriNisekabe),
    (ActorFunc)BgMenkuriNisekabe_Init,
    (ActorFunc)BgMenkuriNisekabe_Destroy,
    (ActorFunc)BgMenkuriNisekabe_Update,
    (ActorFunc)BgMenkuriNisekabe_Draw,
};
*/

#pragma GLOBAL_ASM("binary/BgMenkuriNisekabe_Init.o")

#pragma GLOBAL_ASM("binary/BgMenkuriNisekabe_Destroy.o")

#pragma GLOBAL_ASM("binary/BgMenkuriNisekabe_Update.o")

#pragma GLOBAL_ASM("binary/BgMenkuriNisekabe_Draw.o")
}
