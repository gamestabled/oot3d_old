extern "C" {
#include "z_obj_lift.hpp"

#define FLAGS 0x00400010

void ObjLift_Init(Actor* actor, GameState* state);
void ObjLift_Destroy(Actor* actor, GameState* state);
void ObjLift_Update(Actor* actor, GameState* state);
void ObjLift_Draw(Actor* actor, GameState* state);

GLOBAL_ASM("binary/z_Obj_Lift.data.o")

/*
ActorInit Obj_Lift_InitVars = {
    ACTOR_OBJ_LIFT,
    ACTORCAT_BG,
    FLAGS,
    OBJECT_D_LIFT,
    sizeof(ObjLift),
    (ActorFunc)ObjLift_Init,
    (ActorFunc)ObjLift_Destroy,
    (ActorFunc)ObjLift_Update,
    (ActorFunc)ObjLift_Draw,
};
*/

GLOBAL_ASM("binary/ObjLift_Init.o")

GLOBAL_ASM("binary/ObjLift_Destroy.o")

GLOBAL_ASM("binary/ObjLift_Update.o")

GLOBAL_ASM("binary/ObjLift_Draw.o")
}
