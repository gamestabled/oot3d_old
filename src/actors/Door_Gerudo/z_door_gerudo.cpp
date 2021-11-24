extern "C" {
#include "z_door_gerudo.hpp"

#define FLAGS 0x80400000

void DoorGerudo_Init(Actor* actor, GameState* state);
void DoorGerudo_Destroy(Actor* actor, GameState* state);
void DoorGerudo_Update(Actor* actor, GameState* state);
void DoorGerudo_Draw(Actor* actor, GameState* state);

/*
ActorInit Door_Gerudo_InitVars = {
    ACTOR_DOOR_GERUDO,
    ACTORCAT_ITEMACTION,
    FLAGS,
    OBJECT_DOOR_GERUDO,
    sizeof(DoorGerudo),
    (ActorFunc)DoorGerudo_Init,
    (ActorFunc)DoorGerudo_Destroy,
    (ActorFunc)DoorGerudo_Update,
    (ActorFunc)DoorGerudo_Draw,
};
*/

GLOBAL_ASM("binary/DoorGerudo_Init.o")

GLOBAL_ASM("binary/DoorGerudo_Destroy.o")

GLOBAL_ASM("binary/DoorGerudo_Update.o")

GLOBAL_ASM("binary/DoorGerudo_Draw.o")
}
