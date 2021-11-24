extern "C" {
#include "z_magic_dark.hpp"

#define FLAGS 0x02000030

void MagicDark_Init(Actor* actor, GameState* state);
void MagicDark_Destroy(Actor* actor, GameState* state);
void MagicDark_Update(Actor* actor, GameState* state);
void MagicDark_Draw(Actor* actor, GameState* state);

/*
ActorInit Magic_Dark_InitVars = {
    ACTOR_MAGIC_DARK,
    ACTORCAT_ITEMACTION,
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(MagicDark),
    (ActorFunc)MagicDark_Init,
    (ActorFunc)MagicDark_Destroy,
    (ActorFunc)MagicDark_Update,
    (ActorFunc)MagicDark_Draw,
};
*/

GLOBAL_ASM("binary/MagicDark_Init.o")

GLOBAL_ASM("binary/MagicDark_Destroy.o")

GLOBAL_ASM("binary/MagicDark_Update.o")

GLOBAL_ASM("binary/MagicDark_Draw.o")
}
