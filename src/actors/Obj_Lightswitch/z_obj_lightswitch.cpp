extern "C" {
#include "z_obj_lightswitch.hpp"

#define FLAGS 0x00000010

void ObjLightswitch_Init(Actor* actor, GameState* state);
void ObjLightswitch_Destroy(Actor* actor, GameState* state);
void ObjLightswitch_Update(Actor* actor, GameState* state);
void ObjLightswitch_Draw(Actor* actor, GameState* state);

/*
ActorInit Obj_Lightswitch_InitVars = {
    ACTOR_OBJ_LIGHTSWITCH,
    ACTORCAT_SWITCH,
    FLAGS,
    OBJECT_LIGHTSWITCH,
    sizeof(ObjLightswitch),
    (ActorFunc)ObjLightswitch_Init,
    (ActorFunc)ObjLightswitch_Destroy,
    (ActorFunc)ObjLightswitch_Update,
    (ActorFunc)ObjLightswitch_Draw,
};
*/

GLOBAL_ASM("binary/ObjLightswitch_Init.o")

GLOBAL_ASM("binary/ObjLightswitch_Destroy.o")

GLOBAL_ASM("binary/ObjLightswitch_Update.o")

GLOBAL_ASM("binary/ObjLightswitch_Draw.o")
}
