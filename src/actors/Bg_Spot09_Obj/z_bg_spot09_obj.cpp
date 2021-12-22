extern "C" {
#include "z_bg_spot09_obj.hpp"

#define FLAGS 0x00400000

void BgSpot09Obj_Init(Actor* actor, GameState* state);
void BgSpot09Obj_Destroy(Actor* actor, GameState* state);
void BgSpot09Obj_Update(Actor* actor, GameState* state);
void BgSpot09Obj_Draw(Actor* actor, GameState* state);

GLOBAL_ASM("binary/z_Bg_Spot09_Obj.data.o")

/*
ActorInit Bg_Spot09_Obj_InitVars = {
    ACTOR_BG_SPOT09_OBJ,
    ACTORCAT_BG,
    FLAGS,
    OBJECT_SPOT09_OBJ,
    sizeof(BgSpot09Obj),
    (ActorFunc)BgSpot09Obj_Init,
    (ActorFunc)BgSpot09Obj_Destroy,
    (ActorFunc)BgSpot09Obj_Update,
    (ActorFunc)BgSpot09Obj_Draw,
};
*/

GLOBAL_ASM("binary/BgSpot09Obj_Init.o")

GLOBAL_ASM("binary/BgSpot09Obj_Destroy.o")

GLOBAL_ASM("binary/BgSpot09Obj_Update.o")

GLOBAL_ASM("binary/BgSpot09Obj_Draw.o")
}
