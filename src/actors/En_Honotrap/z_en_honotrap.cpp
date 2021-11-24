extern "C" {
#include "z_en_honotrap.hpp"

#define FLAGS 0x80000010

void EnHonotrap_Init(Actor* actor, GameState* state);
void EnHonotrap_Destroy(Actor* actor, GameState* state);
void EnHonotrap_Update(Actor* actor, GameState* state);
void EnHonotrap_Draw(Actor* actor, GameState* state);

/*
ActorInit En_Honotrap_InitVars = {
    ACTOR_EN_HONOTRAP,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_GAMEPLAY_DANGEON_KEEP,
    sizeof(EnHonotrap),
    (ActorFunc)EnHonotrap_Init,
    (ActorFunc)EnHonotrap_Destroy,
    (ActorFunc)EnHonotrap_Update,
    (ActorFunc)EnHonotrap_Draw,
};
*/

GLOBAL_ASM("binary/EnHonotrap_Init.o")

GLOBAL_ASM("binary/EnHonotrap_Destroy.o")

GLOBAL_ASM("binary/EnHonotrap_Update.o")

GLOBAL_ASM("binary/EnHonotrap_Draw.o")
}
