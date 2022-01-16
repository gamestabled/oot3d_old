extern "C" {
#include "z_en_it.hpp"

#define FLAGS 0x00000000

void EnIt_Init(Actor* actor, GameState* state);
void EnIt_Destroy(Actor* actor, GameState* state);
void EnIt_Update(Actor* actor, GameState* state);

GLOBAL_ASM("binary/z_En_It.data.o")

ActorInit En_It_InitVars = {
    ACTOR_EN_IT,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(EnIt),
    (ActorFunc)EnIt_Init,
    (ActorFunc)EnIt_Destroy,
    (ActorFunc)EnIt_Update,
    NULL,
};

GLOBAL_ASM("binary/EnIt_Init.o")

GLOBAL_ASM("binary/EnIt_Destroy.o")

GLOBAL_ASM("binary/EnIt_Update.o")
}
