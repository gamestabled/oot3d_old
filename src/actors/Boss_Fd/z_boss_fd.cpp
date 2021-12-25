extern "C" {
#include "z_boss_fd.hpp"

#define FLAGS 0x00000035

void BossFd_Init(Actor* actor, GameState* state);
void BossFd_Destroy(Actor* actor, GameState* state);
void BossFd_Update(Actor* actor, GameState* state);
void BossFd_Draw(Actor* actor, GameState* state);

GLOBAL_ASM("binary/z_Boss_Fd.data.o")

/*
ActorInit Boss_Fd_InitVars = {
    ACTOR_BOSS_FD,
    ACTORCAT_BOSS,
    FLAGS,
    OBJECT_FD,
    sizeof(BossFd),
    (ActorFunc)BossFd_Init,
    (ActorFunc)BossFd_Destroy,
    (ActorFunc)BossFd_Update,
    (ActorFunc)BossFd_Draw,
};
*/

GLOBAL_ASM("binary/BossFd_Init.o")

GLOBAL_ASM("binary/BossFd_Destroy.o")

GLOBAL_ASM("binary/BossFd_Update.o")

GLOBAL_ASM("binary/BossFd_Draw.o")
}
