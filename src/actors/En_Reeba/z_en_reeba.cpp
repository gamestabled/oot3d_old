extern "C" {
#include "z_en_reeba.hpp"

#define FLAGS 0x08000015

void EnReeba_Init(Actor* actor, GameState* state);
void EnReeba_Destroy(Actor* actor, GameState* state);
void EnReeba_Update(Actor* actor, GameState* state);
void EnReeba_Draw(Actor* actor, GameState* state);

GLOBAL_ASM("binary/z_En_Reeba.data.o")

/*
ActorInit En_Reeba_InitVars = {
    ACTOR_EN_REEBA,
    ACTORCAT_ENEMY,
    FLAGS,
    OBJECT_REEBA,
    sizeof(EnReeba),
    (ActorFunc)EnReeba_Init,
    (ActorFunc)EnReeba_Destroy,
    (ActorFunc)EnReeba_Update,
    (ActorFunc)EnReeba_Draw,
};
*/

GLOBAL_ASM("binary/EnReeba_Init.o")

GLOBAL_ASM("binary/EnReeba_Destroy.o")

GLOBAL_ASM("binary/EnReeba_Update.o")

GLOBAL_ASM("binary/EnReeba_Draw.o")
}
