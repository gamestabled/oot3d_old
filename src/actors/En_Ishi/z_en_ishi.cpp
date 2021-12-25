extern "C" {
#include "z_en_ishi.hpp"

#define FLAGS 0x80C00000

void EnIshi_Init(Actor* actor, GameState* state);
void EnIshi_Destroy(Actor* actor, GameState* state);
void EnIshi_Update(Actor* actor, GameState* state);
void EnIshi_Draw(Actor* actor, GameState* state);

GLOBAL_ASM("binary/z_En_Ishi.data.o")

/*
ActorInit En_Ishi_InitVars = {
    ACTOR_EN_ISHI,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_GAMEPLAY_FIELD_KEEP,
    sizeof(EnIshi),
    (ActorFunc)EnIshi_Init,
    (ActorFunc)EnIshi_Destroy,
    (ActorFunc)EnIshi_Update,
    (ActorFunc)EnIshi_Draw,
};
*/

GLOBAL_ASM("binary/EnIshi_Init.o")

GLOBAL_ASM("binary/EnIshi_Destroy.o")

GLOBAL_ASM("binary/EnIshi_Update.o")

GLOBAL_ASM("binary/EnIshi_Draw.o")
}
