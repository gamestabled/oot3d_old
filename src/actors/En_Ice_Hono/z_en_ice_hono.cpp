extern "C" {
#include "z_en_ice_hono.hpp"

#define FLAGS 0x00000000

void EnIceHono_Init(Actor* actor, GameState* state);
void EnIceHono_Destroy(Actor* actor, GameState* state);
void EnIceHono_Update(Actor* actor, GameState* state);
void EnIceHono_Draw(Actor* actor, GameState* state);

GLOBAL_ASM("binary/z_En_Ice_Hono.data.o")

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

GLOBAL_ASM("binary/EnIceHono_Init.o")

GLOBAL_ASM("binary/EnIceHono_Destroy.o")

GLOBAL_ASM("binary/EnIceHono_Update.o")

GLOBAL_ASM("binary/EnIceHono_Draw.o")
}
