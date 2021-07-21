extern "C" {
#include "z_door_killer.hpp"

#define FLAGS 0x80000010

void DoorKiller_Init(Actor* actor, GameState* state);
void DoorKiller_Destroy(Actor* actor, GameState* state);
void DoorKiller_Update(Actor* actor, GameState* state);

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
}
