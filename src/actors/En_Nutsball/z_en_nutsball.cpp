extern "C" {
#include "z_en_nutsball.hpp"

#define FLAGS 0x00000010

void EnNutsball_Init(Actor* actor, GameState* state);
void EnNutsball_Destroy(Actor* actor, GameState* state);
void EnNutsball_Update(Actor* actor, GameState* state);

GLOBAL_ASM("binary/z_En_Nutsball.data.o")

ActorInit En_Nutsball_InitVars = {
    ACTOR_EN_NUTSBALL,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(EnNutsball),
    (ActorFunc)EnNutsball_Init,
    (ActorFunc)EnNutsball_Destroy,
    (ActorFunc)EnNutsball_Update,
    NULL,
};

GLOBAL_ASM("binary/EnNutsball_Init.o")

GLOBAL_ASM("binary/EnNutsball_Destroy.o")

GLOBAL_ASM("binary/EnNutsball_Update.o")
}
