extern "C" {
#include "z_en_rr.hpp"

#define FLAGS 0x00000435

void EnRr_Init(Actor* actor, GameState* state);
void EnRr_Destroy(Actor* actor, GameState* state);
void EnRr_Update(Actor* actor, GameState* state);
void EnRr_Draw(Actor* actor, GameState* state);

GLOBAL_ASM("binary/z_En_Rr.data.o")

/*
ActorInit En_Rr_InitVars = {
    ACTOR_EN_RR,
    ACTORCAT_ENEMY,
    FLAGS,
    OBJECT_RR,
    sizeof(EnRr),
    (ActorFunc)EnRr_Init,
    (ActorFunc)EnRr_Destroy,
    (ActorFunc)EnRr_Update,
    (ActorFunc)EnRr_Draw,
};
*/

GLOBAL_ASM("binary/EnRr_Init.o")

GLOBAL_ASM("binary/EnRr_Destroy.o")

GLOBAL_ASM("binary/EnRr_Update.o")

GLOBAL_ASM("binary/EnRr_Draw.o")
}
