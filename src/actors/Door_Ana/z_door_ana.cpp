extern "C" {
#include "z_door_ana.hpp"

#define FLAGS 0x82400000

void DoorAna_Init(Actor* actor, GameState* state);
void DoorAna_Destroy(Actor* actor, GameState* state);
void DoorAna_Update(Actor* actor, GameState* state);
void DoorAna_Draw(Actor* actor, GameState* state);

/*
ActorInit Door_Ana_InitVars = {
    ACTOR_DOOR_ANA,
    ACTORCAT_ITEMACTION,
    FLAGS,
    OBJECT_GAMEPLAY_FIELD_KEEP,
    sizeof(DoorAna),
    (ActorFunc)DoorAna_Init,
    (ActorFunc)DoorAna_Destroy,
    (ActorFunc)DoorAna_Update,
    (ActorFunc)DoorAna_Draw,
};
*/
}
