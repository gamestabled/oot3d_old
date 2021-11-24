extern "C" {
#include "z_en_rd.hpp"

#define FLAGS 0x00000415

void EnRd_Init(Actor* actor, GameState* state);
void EnRd_Destroy(Actor* actor, GameState* state);
void EnRd_Update(Actor* actor, GameState* state);
void EnRd_Draw(Actor* actor, GameState* state);

/*
ActorInit En_Rd_InitVars = {
    ACTOR_EN_RD,
    ACTORCAT_ENEMY,
    FLAGS,
    OBJECT_RD,
    sizeof(EnRd),
    (ActorFunc)EnRd_Init,
    (ActorFunc)EnRd_Destroy,
    (ActorFunc)EnRd_Update,
    (ActorFunc)EnRd_Draw,
};
*/

GLOBAL_ASM("binary/EnRd_Init.o")

GLOBAL_ASM("binary/EnRd_Destroy.o")

GLOBAL_ASM("binary/EnRd_Update.o")

GLOBAL_ASM("binary/EnRd_Draw.o")
}
