extern "C" {
#include "z_boss_dodongo.hpp"

#define FLAGS 0x00000035

void BossDodongo_Init(Actor* actor, GameState* state);
void BossDodongo_Destroy(Actor* actor, GameState* state);
void BossDodongo_Update(Actor* actor, GameState* state);
void BossDodongo_Draw(Actor* actor, GameState* state);

/*
ActorInit Boss_Dodongo_InitVars = {
    ACTOR_EN_DODONGO,
    ACTORCAT_BOSS,
    FLAGS,
    OBJECT_KINGDODONGO,
    sizeof(BossDodongo),
    (ActorFunc)BossDodongo_Init,
    (ActorFunc)BossDodongo_Destroy,
    (ActorFunc)BossDodongo_Update,
    (ActorFunc)BossDodongo_Draw,
};
*/

#pragma GLOBAL_ASM("binary/BossDodongo_Init.o")

#pragma GLOBAL_ASM("binary/BossDodongo_Destroy.o")

#pragma GLOBAL_ASM("binary/BossDodongo_Update.o")

#pragma GLOBAL_ASM("binary/BossDodongo_Draw.o")
}
