extern "C" {
#include "z_en_insect.hpp"

#define FLAGS 0x00000000

void EnInsect_Init(Actor* actor, GameState* state);
void EnInsect_Destroy(Actor* actor, GameState* state);
void EnInsect_Update(Actor* actor, GameState* state);
void EnInsect_Draw(Actor* actor, GameState* state);

GLOBAL_ASM("binary/z_En_Insect.data.o")

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

GLOBAL_ASM("binary/EnInsect_Init.o")

GLOBAL_ASM("binary/EnInsect_Destroy.o")

GLOBAL_ASM("binary/EnInsect_Update.o")

GLOBAL_ASM("binary/EnInsect_Draw.o")
}
