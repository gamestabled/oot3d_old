extern "C" {
#include "z_en_dodojr.hpp"

#define FLAGS 0x00000005

void EnDodojr_Init(Actor* actor, GameState* state);
void EnDodojr_Destroy(Actor* actor, GameState* state);
void EnDodojr_Update(Actor* actor, GameState* state);
void EnDodojr_Draw(Actor* actor, GameState* state);

/*
ActorInit En_Dodojr_InitVars = {
    ACTOR_EN_DODOJR,
    ACTORCAT_ENEMY,
    FLAGS,
    OBJECT_DODOJR,
    sizeof(EnDodojr),
    (ActorFunc)EnDodojr_Init,
    (ActorFunc)EnDodojr_Destroy,
    (ActorFunc)EnDodojr_Update,
    (ActorFunc)EnDodojr_Draw,
};
*/

#pragma GLOBAL_ASM("binary/EnDodojr_Init.o")

#pragma GLOBAL_ASM("binary/EnDodojr_Destroy.o")

#pragma GLOBAL_ASM("binary/EnDodojr_Update.o")

#pragma GLOBAL_ASM("binary/EnDodojr_Draw.o")
}
