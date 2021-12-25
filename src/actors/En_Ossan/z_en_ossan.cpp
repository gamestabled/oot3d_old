extern "C" {
#include "z_en_ossan.hpp"

#define FLAGS 0x00000019

void EnOssan_Init(Actor* actor, GameState* state);
void EnOssan_Destroy(Actor* actor, GameState* state);
void EnOssan_Update(Actor* actor, GameState* state);

GLOBAL_ASM("binary/z_En_Ossan.data.o")

/*
ActorInit En_Ossan_InitVars = {
    ACTOR_EN_OSSAN,
    ACTORCAT_NPC,
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(EnOssan),
    (ActorFunc)EnOssan_Init,
    (ActorFunc)EnOssan_Destroy,
    (ActorFunc)EnOssan_Update,
    (ActorFunc)NULL,
};
*/

GLOBAL_ASM("binary/EnOssan_Init.o")

GLOBAL_ASM("binary/EnOssan_Destroy.o")

GLOBAL_ASM("binary/EnOssan_Update.o")
}
