extern "C" {
#include "z_en_anubice_fire.hpp"

#define FLAGS 0x00000010

void EnAnubiceFire_Init(Actor* actor, GameState* state);
void EnAnubiceFire_Destroy(Actor* actor, GameState* state);
void EnAnubiceFire_Update(Actor* actor, GameState* state);
void EnAnubiceFire_Draw(Actor* actor, GameState* state);

/*
ActorInit En_Anubice_Fire_InitVars = {
    ACTOR_EN_ANUBICE_FIRE,
    ACTORCAT_ENEMY,
    FLAGS,
    OBJECT_ANUBICE,
    sizeof(EnAnubiceFire),
    (ActorFunc)EnAnubiceFire_Init,
    (ActorFunc)EnAnubiceFire_Destroy,
    (ActorFunc)EnAnubiceFire_Update,
    (ActorFunc)EnAnubiceFire_Draw,
};
*/

GLOBAL_ASM("binary/EnAnubiceFire_Init.o")

GLOBAL_ASM("binary/EnAnubiceFire_Destroy.o")

GLOBAL_ASM("binary/EnAnubiceFire_Update.o")

GLOBAL_ASM("binary/EnAnubiceFire_Draw.o")
}
