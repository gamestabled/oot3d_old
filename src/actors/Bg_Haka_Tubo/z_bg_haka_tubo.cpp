extern "C" {
#include "z_bg_haka_tubo.hpp"

#define FLAGS 0x80400010

void BgHakaTubo_Init(Actor* actor, GameState* state);
void BgHakaTubo_Destroy(Actor* actor, GameState* state);
void BgHakaTubo_Update(Actor* actor, GameState* state);
void BgHakaTubo_Draw(Actor* actor, GameState* state);

/*
ActorInit Bg_Haka_Tubo_InitVars = {
    ACTOR_BG_HAKA_TUBO,
    ACTORCAT_BG,
    FLAGS,
    OBJECT_HAKA_OBJECTS,
    sizeof(BgHakaTubo),
    (ActorFunc)BgHakaTubo_Init,
    (ActorFunc)BgHakaTubo_Destroy,
    (ActorFunc)BgHakaTubo_Update,
    (ActorFunc)BgHakaTubo_Draw,
};
*/

GLOBAL_ASM("binary/BgHakaTubo_Init.o")

GLOBAL_ASM("binary/BgHakaTubo_Destroy.o")

GLOBAL_ASM("binary/BgHakaTubo_Update.o")

GLOBAL_ASM("binary/BgHakaTubo_Draw.o")
}
