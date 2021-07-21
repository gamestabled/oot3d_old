extern "C" {
#include "z_door_shutter.hpp"

#define FLAGS 0x00400030

void DoorShutter_Init(Actor* actor, GameState* state);
void DoorShutter_Destroy(Actor* actor, GameState* state);
void DoorShutter_Update(Actor* actor, GameState* state);
void DoorShutter_Draw(Actor* actor, GameState* state);

/*
ActorInit Door_Shutter_InitVars = {
    ACTOR_DOOR_SHUTTER,
    ACTORCAT_DOOR,
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(DoorShutter),
    (ActorFunc)DoorShutter_Init,
    (ActorFunc)DoorShutter_Destroy,
    (ActorFunc)DoorShutter_Update,
    (ActorFunc)DoorShutter_Draw,
};
*/
}
