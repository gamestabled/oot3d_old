extern "C" {
#include "z_en_dekubaba.hpp"

#define FLAGS 0x00000005

void EnDekubaba_Init(Actor* actor, GameState* state);
void EnDekubaba_Destroy(Actor* actor, GameState* state);
void EnDekubaba_Update(Actor* actor, GameState* state);
void EnDekubaba_Draw(Actor* actor, GameState* state);

/*
ActorInit En_Dekubaba_InitVars = {
    ACTOR_EN_DEKUBABA,
    ACTORCAT_ENEMY,
    FLAGS,
    OBJECT_DEKUBABA,
    sizeof(EnDekubaba),
    (ActorFunc)EnDekubaba_Init,
    (ActorFunc)EnDekubaba_Destroy,
    (ActorFunc)EnDekubaba_Update,
    (ActorFunc)EnDekubaba_Draw,
};
*/

GLOBAL_ASM("binary/EnDekubaba_Init.o")

GLOBAL_ASM("binary/EnDekubaba_Destroy.o")

GLOBAL_ASM("binary/EnDekubaba_Update.o")

GLOBAL_ASM("binary/EnDekubaba_Draw.o")
}
