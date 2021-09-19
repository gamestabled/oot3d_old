extern "C" {
#include "z_en_item00.hpp"

#define FLAGS 0x00000000

void EnItem00_Init(Actor* actor, GameState* state);
void EnItem00_Destroy(Actor* actor, GameState* state);
void EnItem00_Update(Actor* actor, GameState* state);
void EnItem00_Draw(Actor* actor, GameState* state);

/*
ActorInit En_Item00_InitVars = {
    ACTOR_EN_ITEM00,
    ACTORCAT_MISC,
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(EnItem00),
    (ActorFunc)EnItem00_Init,
    (ActorFunc)EnItem00_Destroy,
    (ActorFunc)EnItem00_Update,
    (ActorFunc)EnItem00_Draw,
};
*/

#pragma GLOBAL_ASM("binary/EnItem00_Init.o")

#pragma GLOBAL_ASM("binary/EnItem00_Destroy.o")

#pragma GLOBAL_ASM("binary/EnItem00_Update.o")

#pragma GLOBAL_ASM("binary/EnItem00_Draw.o")
}
