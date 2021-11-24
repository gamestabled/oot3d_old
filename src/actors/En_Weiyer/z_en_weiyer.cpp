extern "C" {
#include "z_en_weiyer.hpp"

#define FLAGS 0x00000005

void EnWeiyer_Init(Actor* actor, GameState* state);
void EnWeiyer_Destroy(Actor* actor, GameState* state);
void EnWeiyer_Update(Actor* actor, GameState* state);
void EnWeiyer_Draw(Actor* actor, GameState* state);

/*
ActorInit En_Weiyer_InitVars = {
    ACTOR_EN_WEIYER,
    ACTORCAT_ENEMY,
    FLAGS,
    OBJECT_EI,
    sizeof(EnWeiyer),
    (ActorFunc)EnWeiyer_Init,
    (ActorFunc)EnWeiyer_Destroy,
    (ActorFunc)EnWeiyer_Update,
    (ActorFunc)EnWeiyer_Draw,
};
*/

GLOBAL_ASM("binary/EnWeiyer_Init.o")

GLOBAL_ASM("binary/EnWeiyer_Destroy.o")

GLOBAL_ASM("binary/EnWeiyer_Update.o")

GLOBAL_ASM("binary/EnWeiyer_Draw.o")
}
