extern "C" {
#include "z_en_crow.hpp"

#define FLAGS 0x00005005

void EnCrow_Init(Actor* actor, GameState* state);
void EnCrow_Destroy(Actor* actor, GameState* state);
void EnCrow_Update(Actor* actor, GameState* state);
void EnCrow_Draw(Actor* actor, GameState* state);

/*
ActorInit En_Crow_InitVars = {
    ACTOR_EN_CROW,
    ACTORCAT_ENEMY,
    FLAGS,
    OBJECT_CROW,
    sizeof(EnCrow),
    (ActorFunc)EnCrow_Init,
    (ActorFunc)EnCrow_Destroy,
    (ActorFunc)EnCrow_Update,
    (ActorFunc)EnCrow_Draw,
};
*/

#pragma GLOBAL_ASM("binary/EnCrow_Init.o")

#pragma GLOBAL_ASM("binary/EnCrow_Destroy.o")

#pragma GLOBAL_ASM("binary/EnCrow_Update.o")

#pragma GLOBAL_ASM("binary/EnCrow_Draw.o")
}
