extern "C" {
#include "z_obj_ice_poly.hpp"

#define FLAGS 0x80400010

void ObjIcePoly_Init(Actor* actor, GameState* state);
void ObjIcePoly_Destroy(Actor* actor, GameState* state);
void ObjIcePoly_Update(Actor* actor, GameState* state);
void ObjIcePoly_Draw(Actor* actor, GameState* state);

/*
ActorInit Obj_Ice_Poly_InitVars = {
    ACTOR_OBJ_ICE_POLY,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(ObjIcePoly),
    (ActorFunc)ObjIcePoly_Init,
    (ActorFunc)ObjIcePoly_Destroy,
    (ActorFunc)ObjIcePoly_Update,
    (ActorFunc)ObjIcePoly_Draw,
};
*/

GLOBAL_ASM("binary/ObjIcePoly_Init.o")

GLOBAL_ASM("binary/ObjIcePoly_Destroy.o")

GLOBAL_ASM("binary/ObjIcePoly_Update.o")

GLOBAL_ASM("binary/ObjIcePoly_Draw.o")
}
