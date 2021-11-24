extern "C" {
#include "z_en_niw.hpp"

#define FLAGS 0x00800010

void EnNiw_Init(Actor* actor, GameState* state);
void EnNiw_Destroy(Actor* actor, GameState* state);
void EnNiw_Update(Actor* actor, GameState* state);
void EnNiw_Draw(Actor* actor, GameState* state);

/*
ActorInit En_Niw_InitVars = {
    ACTOR_EN_NIW,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_NIW,
    sizeof(EnNiw),
    (ActorFunc)EnNiw_Init,
    (ActorFunc)EnNiw_Destroy,
    (ActorFunc)EnNiw_Update,
    (ActorFunc)EnNiw_Draw,
};
*/

GLOBAL_ASM("binary/EnNiw_Init.o")

GLOBAL_ASM("binary/EnNiw_Destroy.o")

GLOBAL_ASM("binary/EnNiw_Update.o")

GLOBAL_ASM("binary/EnNiw_Draw.o")
}
