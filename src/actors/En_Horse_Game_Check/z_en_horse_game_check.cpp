extern "C" {
#include "z_en_horse_game_check.hpp"

#define FLAGS 0x00000010

void EnHorseGameCheck_Init(Actor* actor, GameState* state);
void EnHorseGameCheck_Destroy(Actor* actor, GameState* state);
void EnHorseGameCheck_Update(Actor* actor, GameState* state);
void EnHorseGameCheck_Draw(Actor* actor, GameState* state);

/*
ActorInit En_Horse_Game_Check_InitVars = {
    ACTOR_EN_HORSE_GAME_CHECK,
    ACTORCAT_BG,
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(EnHorseGameCheck),
    (ActorFunc)EnHorseGameCheck_Init,
    (ActorFunc)EnHorseGameCheck_Destroy,
    (ActorFunc)EnHorseGameCheck_Update,
    (ActorFunc)EnHorseGameCheck_Draw,
};
*/

#pragma GLOBAL_ASM("binary/EnHorseGameCheck_Init.o")

#pragma GLOBAL_ASM("binary/EnHorseGameCheck_Destroy.o")

#pragma GLOBAL_ASM("binary/EnHorseGameCheck_Update.o")

#pragma GLOBAL_ASM("binary/EnHorseGameCheck_Draw.o")
}
