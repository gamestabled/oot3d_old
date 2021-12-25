extern "C" {
#include "z_en_karebaba.hpp"

#define FLAGS 0x00000005

void EnKarebaba_Init(Actor* actor, GameState* state);
void EnKarebaba_Destroy(Actor* actor, GameState* state);
void EnKarebaba_Update(Actor* actor, GameState* state);
void EnKarebaba_Draw(Actor* actor, GameState* state);

GLOBAL_ASM("binary/z_En_Karebaba.data.o")

/*
ActorInit En_Karebaba_InitVars = {
    ACTOR_EN_KAREBABA,
    ACTORCAT_ENEMY,
    FLAGS,
    OBJECT_DEKUBABA,
    sizeof(EnKarebaba),
    (ActorFunc)EnKarebaba_Init,
    (ActorFunc)EnKarebaba_Destroy,
    (ActorFunc)EnKarebaba_Update,
    (ActorFunc)EnKarebaba_Draw,
};
*/

GLOBAL_ASM("binary/EnKarebaba_Init.o")

GLOBAL_ASM("binary/EnKarebaba_Destroy.o")

GLOBAL_ASM("binary/EnKarebaba_Update.o")

GLOBAL_ASM("binary/EnKarebaba_Draw.o")
}
