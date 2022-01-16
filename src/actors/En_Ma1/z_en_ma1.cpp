extern "C" {
#include "z_en_ma1.hpp"

#define FLAGS 0x02000039

void EnMa1_Init(Actor* actor, GameState* state);
void EnMa1_Destroy(Actor* actor, GameState* state);
void EnMa1_Update(Actor* actor, GameState* state);
void EnMa1_Draw(Actor* actor, GameState* state);

GLOBAL_ASM("binary/z_En_Ma1.data.o")

ActorInit En_Ma1_InitVars = {
    ACTOR_EN_MA1,
    ACTORCAT_NPC,
    FLAGS,
    OBJECT_MA1,
    sizeof(EnMa1),
    (ActorFunc)EnMa1_Init,
    (ActorFunc)EnMa1_Destroy,
    (ActorFunc)EnMa1_Update,
    (ActorFunc)EnMa1_Draw,
};

GLOBAL_ASM("binary/EnMa1_Init.o")

GLOBAL_ASM("binary/EnMa1_Destroy.o")

GLOBAL_ASM("binary/EnMa1_Update.o")

GLOBAL_ASM("binary/EnMa1_Draw.o")
}
