extern "C" {
#include "z_en_goroiwa.hpp"

#define FLAGS 0x00000010

void EnGoroiwa_Init(Actor* actor, GameState* state);
void EnGoroiwa_Destroy(Actor* actor, GameState* state);
void EnGoroiwa_Update(Actor* actor, GameState* state);
void EnGoroiwa_Draw(Actor* actor, GameState* state);

GLOBAL_ASM("binary/z_En_Goroiwa.data.o")

/*
ActorInit En_Goroiwa_InitVars = {
    ACTOR_EN_GOROIWA,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_GOROIWA,
    sizeof(EnGoroiwa),
    (ActorFunc)EnGoroiwa_Init,
    (ActorFunc)EnGoroiwa_Destroy,
    (ActorFunc)EnGoroiwa_Update,
    (ActorFunc)EnGoroiwa_Draw,
};
*/

GLOBAL_ASM("binary/EnGoroiwa_Init.o")

GLOBAL_ASM("binary/EnGoroiwa_Destroy.o")

GLOBAL_ASM("binary/EnGoroiwa_Update.o")

GLOBAL_ASM("binary/EnGoroiwa_Draw.o")
}
