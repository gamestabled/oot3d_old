extern "C" {
#include "z_en_bigokuta.hpp"

#define FLAGS 0x00000035

void EnBigokuta_Init(Actor* actor, GameState* state);
void EnBigokuta_Destroy(Actor* actor, GameState* state);
void EnBigokuta_Update(Actor* actor, GameState* state);
void EnBigokuta_Draw(Actor* actor, GameState* state);

/*
ActorInit En_Bigokuta_InitVars = {
    ACTOR_EN_BIGOKUTA,
    ACTORCAT_ENEMY,
    FLAGS,
    OBJECT_BIGOKUTA,
    sizeof(EnBigokuta),
    (ActorFunc)EnBigokuta_Init,
    (ActorFunc)EnBigokuta_Destroy,
    (ActorFunc)EnBigokuta_Update,
    (ActorFunc)EnBigokuta_Draw,
};
*/

#pragma GLOBAL_ASM("binary/EnBigokuta_Init.o")

#pragma GLOBAL_ASM("binary/EnBigokuta_Destroy.o")

#pragma GLOBAL_ASM("binary/EnBigokuta_Update.o")

#pragma GLOBAL_ASM("binary/EnBigokuta_Draw.o")
}
