extern "C" {
#include "z_bg_haka_meganebg.hpp"

#define FLAGS 0x80400000

void BgHakaMeganeBG_Init(Actor* actor, GameState* state);
void BgHakaMeganeBG_Destroy(Actor* actor, GameState* state);
void BgHakaMeganeBG_Update(Actor* actor, GameState* state);
void BgHakaMeganeBG_Draw(Actor* actor, GameState* state);

GLOBAL_ASM("binary/z_Bg_Haka_Megane_BG.data.o")

/*
ActorInit Bg_Haka_MeganeBG_InitVars = {
    ACTOR_BG_HAKA_MEGANEBG,
    ACTORCAT_BG,
    FLAGS,
    OBJECT_HAKA_OBJECTS,
    sizeof(BgHakaMeganeBG),
    (ActorFunc)BgHakaMeganeBG_Init,
    (ActorFunc)BgHakaMeganeBG_Destroy,
    (ActorFunc)BgHakaMeganeBG_Update,
    (ActorFunc)BgHakaMeganeBG_Draw,
};
*/

GLOBAL_ASM("binary/BgHakaMeganeBG_Init.o")

GLOBAL_ASM("binary/BgHakaMeganeBG_Destroy.o")

GLOBAL_ASM("binary/BgHakaMeganeBG_Update.o")

GLOBAL_ASM("binary/BgHakaMeganeBG_Draw.o")
}
