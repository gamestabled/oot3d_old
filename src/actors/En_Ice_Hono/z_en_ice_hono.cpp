extern "C" {
#include "z_en_ice_hono.hpp"

#define FLAGS 0x00000000

void EnIceHono_Init(Actor* actor, GameState* state);
void EnIceHono_Destroy(Actor* actor, GameState* state);
void EnIceHono_Update(Actor* actor, GameState* state);
void EnIceHono_Draw(Actor* actor, GameState* state);

/*
ActorInit En_Ice_Hono_InitVars = {
    ACTOR_EN_ICE_HONO,
    ACTORCAT_ITEMACTION,
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(EnIceHono),
    (ActorFunc)EnIceHono_Init,
    (ActorFunc)EnIceHono_Destroy,
    (ActorFunc)EnIceHono_Update,
    (ActorFunc)EnIceHono_Draw,
};
*/

#pragma GLOBAL_ASM("binary/EnIceHono_Init.o")

#pragma GLOBAL_ASM("binary/EnIceHono_Destroy.o")

#pragma GLOBAL_ASM("binary/EnIceHono_Update.o")

#pragma GLOBAL_ASM("binary/EnIceHono_Draw.o")
}
