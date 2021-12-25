extern "C" {
#include "z_en_vb_ball.hpp"

#define FLAGS 0x80000030

void EnVbBall_Init(Actor* actor, GameState* state);
void EnVbBall_Destroy(Actor* actor, GameState* state);
void EnVbBall_Update(Actor* actor, GameState* state);
void EnVbBall_Draw(Actor* actor, GameState* state);

GLOBAL_ASM("binary/z_En_Vb_Ball.data.o")

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

GLOBAL_ASM("binary/EnVbBall_Init.o")

GLOBAL_ASM("binary/EnVbBall_Destroy.o")

GLOBAL_ASM("binary/EnVbBall_Update.o")

GLOBAL_ASM("binary/EnVbBall_Draw.o")
}
