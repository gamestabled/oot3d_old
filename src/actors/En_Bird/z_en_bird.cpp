extern "C" {
#include "z_en_bird.hpp"

#define FLAGS 0x80000000

void EnBird_Init(Actor* actor, GameState* state);
void EnBird_Destroy(Actor* actor, GameState* state);
void EnBird_Update(Actor* actor, GameState* state);
void EnBird_Draw(Actor* actor, GameState* state);

/*
ActorInit En_Bird_InitVars = {
    ACTOR_EN_BIRD,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_BIRD,
    sizeof(EnBird),
    (ActorFunc)EnBird_Init,
    (ActorFunc)EnBird_Destroy,
    (ActorFunc)EnBird_Update,
    (ActorFunc)EnBird_Draw,
};
*/

GLOBAL_ASM("binary/EnBird_Init.o")

GLOBAL_ASM("binary/EnBird_Destroy.o")

GLOBAL_ASM("binary/EnBird_Update.o")

GLOBAL_ASM("binary/EnBird_Draw.o")
}
