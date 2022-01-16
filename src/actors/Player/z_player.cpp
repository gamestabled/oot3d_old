extern "C" {
#include "global.hpp"
#define FLAGS 0x06000035

void Player_Init(Actor* actor, GameState* state);
void Player_Destroy(Actor* actor, GameState* state);
void Player_Update(Actor* actor, GameState* state);
void Player_Draw(Actor* actor, GameState* state);

GLOBAL_ASM("binary/z_Player.data_00539FB0.o")
GLOBAL_ASM("binary/z_Player.data_0053C924.o")

ActorInit Player_InitVars = {
    ACTOR_PLAYER,
    ACTORCAT_PLAYER,
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(Player),
    (ActorFunc)Player_Init,
    (ActorFunc)Player_Destroy,
    (ActorFunc)Player_Update,
    (ActorFunc)Player_Draw,
};

GLOBAL_ASM("binary/Player_Init.o")

GLOBAL_ASM("binary/Player_Destroy.o")

GLOBAL_ASM("binary/Player_Update.o")

GLOBAL_ASM("binary/Player_Draw.o")
}
