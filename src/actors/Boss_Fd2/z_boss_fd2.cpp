extern "C" {
#include "z_boss_fd2.hpp"

#define FLAGS 0x00000035

void BossFd2_Init(Actor* actor, GameState* state);
void BossFd2_Destroy(Actor* actor, GameState* state);
void BossFd2_Update(Actor* actor, GameState* state);
void BossFd2_Draw(Actor* actor, GameState* state);

GLOBAL_ASM("binary/z_Boss_Fd2.data.o")

/*
ActorInit Boss_Fd2_InitVars = {
    ACTOR_BOSS_FD2,
    ACTORCAT_BOSS,
    FLAGS,
    OBJECT_FD,
    sizeof(BossFd2),
    (ActorFunc)BossFd2_Init,
    (ActorFunc)BossFd2_Destroy,
    (ActorFunc)BossFd2_Update,
    (ActorFunc)BossFd2_Draw,
};
*/

GLOBAL_ASM("binary/BossFd2_Init.o")

GLOBAL_ASM("binary/BossFd2_Destroy.o")

GLOBAL_ASM("binary/BossFd2_Update.o")

GLOBAL_ASM("binary/BossFd2_Draw.o")
}
