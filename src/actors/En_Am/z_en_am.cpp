extern "C" {
#include "z_en_am.hpp"

#define FLAGS 0x84000015

void EnAm_Init(Actor* actor, GameState* state);
void EnAm_Destroy(Actor* actor, GameState* state);
void EnAm_Update(Actor* actor, GameState* state);
void EnAm_Draw(Actor* actor, GameState* state);

/*
ActorInit En_Am_InitVars = {
    ACTOR_EN_AM,
    ACTORCAT_ENEMY,
    FLAGS,
    OBJECT_AM,
    sizeof(EnAm),
    (ActorFunc)EnAm_Init,
    (ActorFunc)EnAm_Destroy,
    (ActorFunc)EnAm_Update,
    (ActorFunc)EnAm_Draw,
};
*/

GLOBAL_ASM("binary/EnAm_Init.o")

GLOBAL_ASM("binary/EnAm_Destroy.o")

GLOBAL_ASM("binary/EnAm_Update.o")

GLOBAL_ASM("binary/EnAm_Draw.o")
}
