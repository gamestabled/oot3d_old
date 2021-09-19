extern "C" {
#include "z_en_changer.hpp"

#define FLAGS 0x80000000

void EnChanger_Init(Actor* actor, GameState* state);
void EnChanger_Destroy(Actor* actor, GameState* state);
void EnChanger_Update(Actor* actor, GameState* state);

/*
ActorInit En_Changer_InitVars = {
    ACTOR_EN_CHANGER,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(EnChanger),
    (ActorFunc)EnChanger_Init,
    (ActorFunc)EnChanger_Destroy,
    (ActorFunc)EnChanger_Update,
    (ActorFunc)NULL,
};
*/

#pragma GLOBAL_ASM("binary/EnChanger_Init.o")

#pragma GLOBAL_ASM("binary/EnChanger_Destroy.o")

#pragma GLOBAL_ASM("binary/EnChanger_Update.o")
}
