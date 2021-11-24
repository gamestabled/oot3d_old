extern "C" {
#include "z_bg_hidan_rock.hpp"

#define FLAGS 0x80400000

void BgHidanRock_Init(Actor* actor, GameState* state);
void BgHidanRock_Destroy(Actor* actor, GameState* state);
void BgHidanRock_Update(Actor* actor, GameState* state);
void BgHidanRock_Draw(Actor* actor, GameState* state);

/*
ActorInit Bg_Hidan_Rock_InitVars = {
    ACTOR_BG_HIDAN_ROCK,
    ACTORCAT_BG,
    FLAGS,
    OBJECT_HIDAN_OBJECTS,
    sizeof(BgHidanRock),
    (ActorFunc)BgHidanRock_Init,
    (ActorFunc)BgHidanRock_Destroy,
    (ActorFunc)BgHidanRock_Update,
    (ActorFunc)BgHidanRock_Draw,
};
*/

GLOBAL_ASM("binary/BgHidanRock_Init.o")

GLOBAL_ASM("binary/BgHidanRock_Destroy.o")

GLOBAL_ASM("binary/BgHidanRock_Update.o")

GLOBAL_ASM("binary/BgHidanRock_Draw.o")
}
