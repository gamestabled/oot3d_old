extern "C" {
#include "z_en_mm.hpp"

#define FLAGS 0x00000019

void EnMm_Init(Actor* actor, GameState* state);
void EnMm_Destroy(Actor* actor, GameState* state);
void EnMm_Update(Actor* actor, GameState* state);
void EnMm_Draw(Actor* actor, GameState* state);

GLOBAL_ASM("binary/z_En_Mm.data.o")

ActorInit En_Mm_InitVars = {
    ACTOR_EN_MM,
    ACTORCAT_NPC,
    FLAGS,
    OBJECT_MM,
    sizeof(EnMm),
    (ActorFunc)EnMm_Init,
    (ActorFunc)EnMm_Destroy,
    (ActorFunc)EnMm_Update,
    (ActorFunc)EnMm_Draw,
};

GLOBAL_ASM("binary/EnMm_Init.o")

GLOBAL_ASM("binary/EnMm_Destroy.o")

GLOBAL_ASM("binary/EnMm_Update.o")

GLOBAL_ASM("binary/EnMm_Draw.o")
}
