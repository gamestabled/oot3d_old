extern "C" {
#include "z_en_yukabyun.hpp"

#define FLAGS 0x00400010

void EnYukabyun_Init(Actor* actor, GameState* state);
void EnYukabyun_Destroy(Actor* actor, GameState* state);
void EnYukabyun_Update(Actor* actor, GameState* state);
void EnYukabyun_Draw(Actor* actor, GameState* state);

GLOBAL_ASM("binary/z_En_Yukabyun.data.o")

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

GLOBAL_ASM("binary/EnYukabyun_Init.o")

GLOBAL_ASM("binary/EnYukabyun_Destroy.o")

GLOBAL_ASM("binary/EnYukabyun_Update.o")

GLOBAL_ASM("binary/EnYukabyun_Draw.o")
}
