extern "C" {
#include "z_en_insect.hpp"

#define FLAGS 0x00000000

void EnInsect_Init(Actor* actor, GameState* state);
void EnInsect_Destroy(Actor* actor, GameState* state);
void EnInsect_Update(Actor* actor, GameState* state);
void EnInsect_Draw(Actor* actor, GameState* state);

/*
ActorInit En_Insect_InitVars = {
    ACTOR_EN_INSECT,
    ACTORCAT_ITEMACTION,
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(EnInsect),
    (ActorFunc)EnInsect_Init,
    (ActorFunc)EnInsect_Destroy,
    (ActorFunc)EnInsect_Update,
    (ActorFunc)EnInsect_Draw,
};
*/

#pragma GLOBAL_ASM("binary/EnInsect_Init.o")

#pragma GLOBAL_ASM("binary/EnInsect_Destroy.o")

#pragma GLOBAL_ASM("binary/EnInsect_Update.o")

#pragma GLOBAL_ASM("binary/EnInsect_Draw.o")
}
