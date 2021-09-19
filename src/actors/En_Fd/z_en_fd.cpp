extern "C" {
#include "z_en_fd.hpp"

#define FLAGS 0x00000215

void EnFd_Init(Actor* actor, GameState* state);
void EnFd_Destroy(Actor* actor, GameState* state);
void EnFd_Update(Actor* actor, GameState* state);
void EnFd_Draw(Actor* actor, GameState* state);

/*
ActorInit En_Fd_InitVars = {
    ACTOR_EN_FD,
    ACTORCAT_ENEMY,
    FLAGS,
    OBJECT_FW,
    sizeof(EnFd),
    (ActorFunc)EnFd_Init,
    (ActorFunc)EnFd_Destroy,
    (ActorFunc)EnFd_Update,
    (ActorFunc)EnFd_Draw,
};
*/

#pragma GLOBAL_ASM("binary/EnFd_Init.o")

#pragma GLOBAL_ASM("binary/EnFd_Destroy.o")

#pragma GLOBAL_ASM("binary/EnFd_Update.o")

#pragma GLOBAL_ASM("binary/EnFd_Draw.o")
}
