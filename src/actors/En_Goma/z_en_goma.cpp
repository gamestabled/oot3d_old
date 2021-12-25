extern "C" {
#include "z_en_goma.hpp"

#define FLAGS 0x00000035

void EnGoma_Init(Actor* actor, GameState* state);
void EnGoma_Destroy(Actor* actor, GameState* state);
void EnGoma_Update(Actor* actor, GameState* state);
void EnGoma_Draw(Actor* actor, GameState* state);

GLOBAL_ASM("binary/z_En_Goma.data.o")

/*
ActorInit En_Goma_InitVars = {
    ACTOR_BOSS_GOMA,
    ACTORCAT_ENEMY,
    FLAGS,
    OBJECT_GOL,
    sizeof(EnGoma),
    (ActorFunc)EnGoma_Init,
    (ActorFunc)EnGoma_Destroy,
    (ActorFunc)EnGoma_Update,
    (ActorFunc)EnGoma_Draw,
};
*/

GLOBAL_ASM("binary/EnGoma_Init.o")

GLOBAL_ASM("binary/EnGoma_Destroy.o")

GLOBAL_ASM("binary/EnGoma_Update.o")

GLOBAL_ASM("binary/EnGoma_Draw.o")
}
