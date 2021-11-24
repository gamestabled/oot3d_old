extern "C" {
#include "z_boss_ganon2.hpp"

#define FLAGS 0x00000035

void BossGanon2_Init(Actor* actor, GameState* state);
void BossGanon2_Destroy(Actor* actor, GameState* state);
void BossGanon2_Update(Actor* actor, GameState* state);
void BossGanon2_Draw(Actor* actor, GameState* state);

/*
ActorInit Boss_Ganon2_InitVars = {
    ACTOR_BOSS_GANON2,
    ACTORCAT_BOSS,
    FLAGS,
    OBJECT_GANON2,
    sizeof(BossGanon2),
    (ActorFunc)BossGanon2_Init,
    (ActorFunc)BossGanon2_Destroy,
    (ActorFunc)BossGanon2_Update,
    (ActorFunc)BossGanon2_Draw,
};
*/

GLOBAL_ASM("binary/BossGanon2_Init.o")

GLOBAL_ASM("binary/BossGanon2_Destroy.o")

GLOBAL_ASM("binary/BossGanon2_Update.o")

GLOBAL_ASM("binary/BossGanon2_Draw.o")
}
