extern "C" {
#include "z_en_door.hpp"

#define FLAGS 0x00400030

void EnDoor_Init(Actor* actor, GameState* state);
void EnDoor_Destroy(Actor* actor, GameState* state);
void EnDoor_Update(Actor* actor, GameState* state);
void EnDoor_Draw(Actor* actor, GameState* state);

/*
ActorInit En_Door_InitVars = {
    ACTOR_EN_DOOR,
    ACTORCAT_DOOR,
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(EnDoor),
    (ActorFunc)EnDoor_Init,
    (ActorFunc)EnDoor_Destroy,
    (ActorFunc)EnDoor_Update,
    (ActorFunc)EnDoor_Draw,
};
*/

#pragma GLOBAL_ASM("binary/EnDoor_Init.o")

#pragma GLOBAL_ASM("binary/EnDoor_Destroy.o")

#pragma GLOBAL_ASM("binary/EnDoor_Update.o")

#pragma GLOBAL_ASM("binary/EnDoor_Draw.o")
}
