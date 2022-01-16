extern "C" {
#include "z_en_si.hpp"

#define FLAGS 0x00000201

void EnSi_Init(Actor* actor, GameState* state);
void EnSi_Destroy(Actor* actor, GameState* state);
void EnSi_Update(Actor* actor, GameState* state);
void EnSi_Draw(Actor* actor, GameState* state);

GLOBAL_ASM("binary/z_En_Si.data.o")

ActorInit En_Si_InitVars = {
    ACTOR_EN_SI,
    ACTORCAT_ITEMACTION,
    FLAGS,
    OBJECT_ST,
    sizeof(EnSi),
    (ActorFunc)EnSi_Init,
    (ActorFunc)EnSi_Destroy,
    (ActorFunc)EnSi_Update,
    (ActorFunc)EnSi_Draw,
};

GLOBAL_ASM("binary/EnSi_Init.o")

GLOBAL_ASM("binary/EnSi_Destroy.o")

GLOBAL_ASM("binary/EnSi_Update.o")

GLOBAL_ASM("binary/EnSi_Draw.o")
}
