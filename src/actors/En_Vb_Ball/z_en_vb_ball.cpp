extern "C" {
#include "z_en_vb_ball.hpp"

#define FLAGS 0x80000030

void EnVbBall_Init(Actor* actor, GameState* state);
void EnVbBall_Destroy(Actor* actor, GameState* state);
void EnVbBall_Update(Actor* actor, GameState* state);
void EnVbBall_Draw(Actor* actor, GameState* state);

/*
ActorInit En_Vb_Ball_InitVars = {
    ACTOR_PLAYER,
    ACTORCAT_BOSS,
    FLAGS,
    OBJECT_FD,
    sizeof(EnVbBall),
    (ActorFunc)EnVbBall_Init,
    (ActorFunc)EnVbBall_Destroy,
    (ActorFunc)EnVbBall_Update,
    (ActorFunc)EnVbBall_Draw,
};
*/

#pragma GLOBAL_ASM("binary/EnVbBall_Init.o")

#pragma GLOBAL_ASM("binary/EnVbBall_Destroy.o")

#pragma GLOBAL_ASM("binary/EnVbBall_Update.o")

#pragma GLOBAL_ASM("binary/EnVbBall_Draw.o")
}
