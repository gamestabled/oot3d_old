extern "C" {
#include "z_obj_kibako2.hpp"

#define FLAGS 0x00000000

void ObjKibako2_Init(Actor* actor, GameState* state);
void ObjKibako2_Destroy(Actor* actor, GameState* state);
void ObjKibako2_Update(Actor* actor, GameState* state);
void ObjKibako2_Draw(Actor* actor, GameState* state);

/*
ActorInit Obj_Kibako2_InitVars = {
    ACTOR_OBJ_KIBAKO2,
    ACTORCAT_BG,
    FLAGS,
    OBJECT_KIBAKO2,
    sizeof(ObjKibako2),
    (ActorFunc)ObjKibako2_Init,
    (ActorFunc)ObjKibako2_Destroy,
    (ActorFunc)ObjKibako2_Update,
    (ActorFunc)ObjKibako2_Draw,
};
*/

#pragma GLOBAL_ASM("binary/ObjKibako2_Init.o")

#pragma GLOBAL_ASM("binary/ObjKibako2_Destroy.o")

#pragma GLOBAL_ASM("binary/ObjKibako2_Update.o")

#pragma GLOBAL_ASM("binary/ObjKibako2_Draw.o")
}
