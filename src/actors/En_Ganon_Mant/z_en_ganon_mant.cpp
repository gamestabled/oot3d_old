extern "C" {
#include "z_en_ganon_mant.hpp"

#define FLAGS 0x00000030

void EnGanonMant_Init(Actor* actor, GameState* state);
void EnGanonMant_Destroy(Actor* actor, GameState* state);
void EnGanonMant_Update(Actor* actor, GameState* state);

GLOBAL_ASM("binary/z_En_Ganon_Mant.data.o")

/*
ActorInit En_Ganon_Mant_InitVars = {
    ACTOR_EN_GANON_MANT,
    ACTORCAT_BOSS,
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(EnGanonMant),
    (ActorFunc)EnGanonMant_Init,
    (ActorFunc)EnGanonMant_Destroy,
    (ActorFunc)EnGanonMant_Update,
    (ActorFunc)NULL,
};
*/

GLOBAL_ASM("binary/EnGanonMant_Init.o")

GLOBAL_ASM("binary/EnGanonMant_Destroy.o")

GLOBAL_ASM("binary/EnGanonMant_Update.o")
}
