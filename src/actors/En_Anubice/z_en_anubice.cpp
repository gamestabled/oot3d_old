extern "C" {
#include "z_en_anubice.hpp"

#define FLAGS 0x00000015

void EnAnubice_Init(Actor* actor, GameState* state);
void EnAnubice_Destroy(Actor* actor, GameState* state);
void EnAnubice_Update(Actor* actor, GameState* state);
void EnAnubice_Draw(Actor* actor, GameState* state);

/*
ActorInit En_Anubice_InitVars = {
    ACTOR_EN_ANUBICE,
    ACTORCAT_ENEMY,
    FLAGS,
    OBJECT_ANUBICE,
    sizeof(EnAnubice),
    (ActorFunc)EnAnubice_Init,
    (ActorFunc)EnAnubice_Destroy,
    (ActorFunc)EnAnubice_Update,
    (ActorFunc)EnAnubice_Draw,
};
*/

GLOBAL_ASM("binary/EnAnubice_Init.o")

GLOBAL_ASM("binary/EnAnubice_Destroy.o")

GLOBAL_ASM("binary/EnAnubice_Update.o")

GLOBAL_ASM("binary/EnAnubice_Draw.o")
}
