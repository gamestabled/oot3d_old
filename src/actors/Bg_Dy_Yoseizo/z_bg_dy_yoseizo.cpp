extern "C" {
#include "z_bg_dy_yoseizo.hpp"

#define FLAGS 0x02000030

void BgDyYoseizo_Init(Actor* actor, GameState* state);
void BgDyYoseizo_Destroy(Actor* actor, GameState* state);
void BgDyYoseizo_Update(Actor* actor, GameState* state);

/*
ActorInit Bg_Dy_Yoseizo_InitVars = {
    ACTOR_BG_DY_YOSEIZO,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_DY_OBJ,
    sizeof(BgDyYoseizo),
    (ActorFunc)BgDyYoseizo_Init,
    (ActorFunc)BgDyYoseizo_Destroy,
    (ActorFunc)BgDyYoseizo_Update,
    (ActorFunc)NULL,
};
*/

GLOBAL_ASM("binary/BgDyYoseizo_Init.o")

GLOBAL_ASM("binary/BgDyYoseizo_Destroy.o")

GLOBAL_ASM("binary/BgDyYoseizo_Update.o")
}
