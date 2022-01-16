extern "C" {
#include "z_en_attack_niw.hpp"

#define FLAGS 0x00000010

void EnAttackNiw_Init(Actor* actor, GameState* state);
void EnAttackNiw_Destroy(Actor* actor, GameState* state);
void EnAttackNiw_Update(Actor* actor, GameState* state);
void EnAttackNiw_Draw(Actor* actor, GameState* state);

GLOBAL_ASM("binary/z_En_Attack_Niw.data.o")

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

GLOBAL_ASM("binary/EnAttackNiw_Init.o")

GLOBAL_ASM("binary/EnAttackNiw_Destroy.o")

GLOBAL_ASM("binary/EnAttackNiw_Update.o")

GLOBAL_ASM("binary/EnAttackNiw_Draw.o")
}
