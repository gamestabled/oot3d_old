extern "C" {
#include "z_door_killer.hpp"

#define FLAGS 0x80000010

void DoorKiller_Init(Actor* actor, GameState* state);
void DoorKiller_Destroy(Actor* actor, GameState* state);
void DoorKiller_Update(Actor* actor, GameState* state);

GLOBAL_ASM("binary/z_Door_Killer.data.o")

/*
ActorInit Door_Killer_InitVars = {
    ACTOR_DOOR_KILLER,
    ACTORCAT_BG,
    FLAGS,
    OBJECT_DOOR_KILLER,
    sizeof(DoorKiller),
    (ActorFunc)DoorKiller_Init,
    (ActorFunc)DoorKiller_Destroy,
    (ActorFunc)DoorKiller_Update,
    (ActorFunc)NULL,
};
*/

GLOBAL_ASM("binary/DoorKiller_Init.o")

GLOBAL_ASM("binary/DoorKiller_Destroy.o")

GLOBAL_ASM("binary/DoorKiller_Update.o")
}
