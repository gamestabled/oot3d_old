extern "C" {
#include "z_fishing.hpp"

#define FLAGS 0x00000010

void Fishing_Init(Actor* actor, GameState* state);
void Fishing_Destroy(Actor* actor, GameState* state);
void Fishing_Update(Actor* actor, GameState* state);
void Fishing_Draw(Actor* actor, GameState* state);

/*
ActorInit Fishing_InitVars = {
    ACTOR_FISHING,
    ACTORCAT_NPC,
    FLAGS,
    OBJECT_FISH,
    sizeof(Fishing),
    (ActorFunc)Fishing_Init,
    (ActorFunc)Fishing_Destroy,
    (ActorFunc)Fishing_Update,
    (ActorFunc)Fishing_Draw,
};
*/

#pragma GLOBAL_ASM("binary/Fishing_Init.o")

#pragma GLOBAL_ASM("binary/Fishing_Destroy.o")

#pragma GLOBAL_ASM("binary/Fishing_Update.o")

#pragma GLOBAL_ASM("binary/Fishing_Draw.o")
}
