extern "C" {
#include "z_bg_gnd_firemeiro.hpp"

#define FLAGS 0x80400030

void BgGndFiremeiro_Init(Actor* actor, GameState* state);
void BgGndFiremeiro_Destroy(Actor* actor, GameState* state);
void BgGndFiremeiro_Update(Actor* actor, GameState* state);
void BgGndFiremeiro_Draw(Actor* actor, GameState* state);

GLOBAL_ASM("binary/z_Bg_Gnd_Firemeiro.data.o")

/*
ActorInit Bg_Gnd_Firemeiro_InitVars = {
    ACTOR_BG_GND_FIREMEIRO,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_DEMO_KEKKAI,
    sizeof(BgGndFiremeiro),
    (ActorFunc)BgGndFiremeiro_Init,
    (ActorFunc)BgGndFiremeiro_Destroy,
    (ActorFunc)BgGndFiremeiro_Update,
    (ActorFunc)BgGndFiremeiro_Draw,
};
*/

GLOBAL_ASM("binary/BgGndFiremeiro_Init.o")

GLOBAL_ASM("binary/BgGndFiremeiro_Destroy.o")

GLOBAL_ASM("binary/BgGndFiremeiro_Update.o")

GLOBAL_ASM("binary/BgGndFiremeiro_Draw.o")
}
