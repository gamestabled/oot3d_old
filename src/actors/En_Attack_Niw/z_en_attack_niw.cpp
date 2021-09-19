extern "C" {
#include "z_en_attack_niw.hpp"

#define FLAGS 0x00000010

void EnAttackNiw_Init(Actor* actor, GameState* state);
void EnAttackNiw_Destroy(Actor* actor, GameState* state);
void EnAttackNiw_Update(Actor* actor, GameState* state);
void EnAttackNiw_Draw(Actor* actor, GameState* state);

/*
ActorInit En_Attack_Niw_InitVars = {
    ACTOR_EN_ATTACK_NIW,
    ACTORCAT_ENEMY,
    FLAGS,
    OBJECT_NIW,
    sizeof(EnAttackNiw),
    (ActorFunc)EnAttackNiw_Init,
    (ActorFunc)EnAttackNiw_Destroy,
    (ActorFunc)EnAttackNiw_Update,
    (ActorFunc)EnAttackNiw_Draw,
};
*/

#pragma GLOBAL_ASM("binary/EnAttackNiw_Init.o")

#pragma GLOBAL_ASM("binary/EnAttackNiw_Destroy.o")

#pragma GLOBAL_ASM("binary/EnAttackNiw_Update.o")

#pragma GLOBAL_ASM("binary/EnAttackNiw_Draw.o")
}
