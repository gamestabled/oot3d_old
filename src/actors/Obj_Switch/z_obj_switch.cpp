extern "C" {
#include "z_obj_switch.hpp"

#define FLAGS 0x00000010

void ObjSwitch_Init(Actor* actor, GameState* state);
void ObjSwitch_Destroy(Actor* actor, GameState* state);
void ObjSwitch_Update(Actor* actor, GameState* state);
void ObjSwitch_Draw(Actor* actor, GameState* state);

/*
ActorInit Obj_Switch_InitVars = {
    ACTOR_OBJ_SWITCH,
    ACTORCAT_SWITCH,
    FLAGS,
    OBJECT_GAMEPLAY_DANGEON_KEEP,
    sizeof(ObjSwitch),
    (ActorFunc)ObjSwitch_Init,
    (ActorFunc)ObjSwitch_Destroy,
    (ActorFunc)ObjSwitch_Update,
    (ActorFunc)ObjSwitch_Draw,
};
*/

GLOBAL_ASM("binary/ObjSwitch_Init.o")

GLOBAL_ASM("binary/ObjSwitch_Destroy.o")

GLOBAL_ASM("binary/ObjSwitch_Update.o")

GLOBAL_ASM("binary/ObjSwitch_Draw.o")
}
