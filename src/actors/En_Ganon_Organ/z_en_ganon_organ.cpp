extern "C" {
#include "z_en_ganon_organ.hpp"

#define FLAGS 0x00400030

void EnGanonOrgan_Init(Actor* actor, GameState* state);
void EnGanonOrgan_Destroy(Actor* actor, GameState* state);
void EnGanonOrgan_Update(Actor* actor, GameState* state);
void EnGanonOrgan_Draw(Actor* actor, GameState* state);

GLOBAL_ASM("binary/z_En_Ganon_Organ.data.o")

/*
ActorInit En_Ganon_Organ_InitVars = {
    ACTOR_EN_GANON_ORGAN,
    ACTORCAT_BOSS,
    FLAGS,
    OBJECT_GANON,
    sizeof(EnGanonOrgan),
    (ActorFunc)EnGanonOrgan_Init,
    (ActorFunc)EnGanonOrgan_Destroy,
    (ActorFunc)EnGanonOrgan_Update,
    (ActorFunc)EnGanonOrgan_Draw,
};
*/

GLOBAL_ASM("binary/EnGanonOrgan_Init.o")

GLOBAL_ASM("binary/EnGanonOrgan_Destroy.o")

GLOBAL_ASM("binary/EnGanonOrgan_Update.o")

GLOBAL_ASM("binary/EnGanonOrgan_Draw.o")
}
