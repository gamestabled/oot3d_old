extern "C" {
#include "z_bg_haka_huta.hpp"

#define FLAGS 0x80000010

void BgHakaHuta_Init(Actor* actor, GameState* state);
void BgHakaHuta_Destroy(Actor* actor, GameState* state);
void BgHakaHuta_Update(Actor* actor, GameState* state);
void BgHakaHuta_Draw(Actor* actor, GameState* state);

/*
ActorInit Bg_Haka_Huta_InitVars = {
    ACTOR_BG_HAKA_HUTA,
    ACTORCAT_BG,
    FLAGS,
    OBJECT_HAKACH_OBJECTS,
    sizeof(BgHakaHuta),
    (ActorFunc)BgHakaHuta_Init,
    (ActorFunc)BgHakaHuta_Destroy,
    (ActorFunc)BgHakaHuta_Update,
    (ActorFunc)BgHakaHuta_Draw,
};
*/

GLOBAL_ASM("binary/BgHakaHuta_Init.o")

GLOBAL_ASM("binary/BgHakaHuta_Destroy.o")

GLOBAL_ASM("binary/BgHakaHuta_Update.o")

GLOBAL_ASM("binary/BgHakaHuta_Draw.o")
}
