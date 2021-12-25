extern "C" {
#include "z_en_dnt_jiji.hpp"

#define FLAGS 0x00000019

void EnDntJiji_Init(Actor* actor, GameState* state);
void EnDntJiji_Destroy(Actor* actor, GameState* state);
void EnDntJiji_Update(Actor* actor, GameState* state);
void EnDntJiji_Draw(Actor* actor, GameState* state);

GLOBAL_ASM("binary/z_En_Dnt_Jiji.data.o")

/*
ActorInit En_Dnt_Jiji_InitVars = {
    ACTOR_EN_DNT_JIJI,
    ACTORCAT_NPC,
    FLAGS,
    OBJECT_DNS,
    sizeof(EnDntJiji),
    (ActorFunc)EnDntJiji_Init,
    (ActorFunc)EnDntJiji_Destroy,
    (ActorFunc)EnDntJiji_Update,
    (ActorFunc)EnDntJiji_Draw,
};
*/

GLOBAL_ASM("binary/EnDntJiji_Init.o")

GLOBAL_ASM("binary/EnDntJiji_Destroy.o")

GLOBAL_ASM("binary/EnDntJiji_Update.o")

GLOBAL_ASM("binary/EnDntJiji_Draw.o")
}
