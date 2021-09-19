extern "C" {
#include "z_bg_ydan_maruta.hpp"

#define FLAGS 0x80000010

void BgYdanMaruta_Init(Actor* actor, GameState* state);
void BgYdanMaruta_Destroy(Actor* actor, GameState* state);
void BgYdanMaruta_Update(Actor* actor, GameState* state);
void BgYdanMaruta_Draw(Actor* actor, GameState* state);

/*
ActorInit Bg_Ydan_Maruta_InitVars = {
    ACTOR_BG_YDAN_MARUTA,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_YDAN_OBJECTS,
    sizeof(BgYdanMaruta),
    (ActorFunc)BgYdanMaruta_Init,
    (ActorFunc)BgYdanMaruta_Destroy,
    (ActorFunc)BgYdanMaruta_Update,
    (ActorFunc)BgYdanMaruta_Draw,
};
*/

#pragma GLOBAL_ASM("binary/BgYdanMaruta_Init.o")

#pragma GLOBAL_ASM("binary/BgYdanMaruta_Destroy.o")

#pragma GLOBAL_ASM("binary/BgYdanMaruta_Update.o")

#pragma GLOBAL_ASM("binary/BgYdanMaruta_Draw.o")
}
