extern "C" {
#include "z_magic_fire.hpp"

#define FLAGS 0x02000010

void MagicFire_Init(Actor* actor, GameState* state);
void MagicFire_Destroy(Actor* actor, GameState* state);
void MagicFire_Update(Actor* actor, GameState* state);
void MagicFire_Draw(Actor* actor, GameState* state);

/*
ActorInit Magic_Fire_InitVars = {
    ACTOR_MAGIC_FIRE,
    ACTORCAT_ITEMACTION,
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(MagicFire),
    (ActorFunc)MagicFire_Init,
    (ActorFunc)MagicFire_Destroy,
    (ActorFunc)MagicFire_Update,
    (ActorFunc)MagicFire_Draw,
};
*/

GLOBAL_ASM("binary/MagicFire_Init.o")

GLOBAL_ASM("binary/MagicFire_Destroy.o")

GLOBAL_ASM("binary/MagicFire_Update.o")

GLOBAL_ASM("binary/MagicFire_Draw.o")
}
