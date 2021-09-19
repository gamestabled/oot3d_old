extern "C" {
#include "z_en_yukabyun.hpp"

#define FLAGS 0x00400010

void EnYukabyun_Init(Actor* actor, GameState* state);
void EnYukabyun_Destroy(Actor* actor, GameState* state);
void EnYukabyun_Update(Actor* actor, GameState* state);
void EnYukabyun_Draw(Actor* actor, GameState* state);

/*
ActorInit En_Yukabyun_InitVars = {
    ACTOR_EN_YUKABYUN,
    ACTORCAT_ENEMY,
    FLAGS,
    OBJECT_YUKABYUN,
    sizeof(EnYukabyun),
    (ActorFunc)EnYukabyun_Init,
    (ActorFunc)EnYukabyun_Destroy,
    (ActorFunc)EnYukabyun_Update,
    (ActorFunc)EnYukabyun_Draw,
};
*/

#pragma GLOBAL_ASM("binary/EnYukabyun_Init.o")

#pragma GLOBAL_ASM("binary/EnYukabyun_Destroy.o")

#pragma GLOBAL_ASM("binary/EnYukabyun_Update.o")

#pragma GLOBAL_ASM("binary/EnYukabyun_Draw.o")
}
