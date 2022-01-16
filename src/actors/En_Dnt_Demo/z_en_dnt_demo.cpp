extern "C" {
#include "z_en_dnt_demo.hpp"

#define FLAGS 0x00000000

void EnDntDemo_Init(Actor* actor, GameState* state);
void EnDntDemo_Destroy(Actor* actor, GameState* state);
void EnDntDemo_Update(Actor* actor, GameState* state);

GLOBAL_ASM("binary/z_En_Dnt_Demo.data.o")

ActorInit En_Dnt_Demo_InitVars = {
    ACTOR_EN_DNT_DEMO,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(EnDntDemo),
    (ActorFunc)EnDntDemo_Init,
    (ActorFunc)EnDntDemo_Destroy,
    (ActorFunc)EnDntDemo_Update,
    NULL,
};

GLOBAL_ASM("binary/EnDntDemo_Init.o")

GLOBAL_ASM("binary/EnDntDemo_Destroy.o")

GLOBAL_ASM("binary/EnDntDemo_Update.o")
}
