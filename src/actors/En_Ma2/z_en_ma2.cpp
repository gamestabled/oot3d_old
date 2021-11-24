extern "C" {
#include "z_en_ma2.hpp"

#define FLAGS 0x02000039

void EnMa2_Init(Actor* actor, GameState* state);
void EnMa2_Destroy(Actor* actor, GameState* state);
void EnMa2_Update(Actor* actor, GameState* state);
void EnMa2_Draw(Actor* actor, GameState* state);

/*
ActorInit En_Ma2_InitVars = {
    ACTOR_EN_MA2,
    ACTORCAT_NPC,
    FLAGS,
    OBJECT_MA2,
    sizeof(EnMa2),
    (ActorFunc)EnMa2_Init,
    (ActorFunc)EnMa2_Destroy,
    (ActorFunc)EnMa2_Update,
    (ActorFunc)EnMa2_Draw,
};
*/

GLOBAL_ASM("binary/EnMa2_Init.o")

GLOBAL_ASM("binary/EnMa2_Destroy.o")

GLOBAL_ASM("binary/EnMa2_Update.o")

GLOBAL_ASM("binary/EnMa2_Draw.o")
}
