extern "C" {
#include "z_bg_spot02_objects.hpp"

#define FLAGS 0x00000030

void BgSpot02Objects_Init(Actor* actor, GameState* state);
void BgSpot02Objects_Destroy(Actor* actor, GameState* state);
void BgSpot02Objects_Update(Actor* actor, GameState* state);
void BgSpot02Objects_Draw(Actor* actor, GameState* state);

GLOBAL_ASM("binary/z_Bg_Spot02_Objects.data.o")

ActorInit Bg_Spot02_Objects_InitVars = {
    ACTOR_BG_SPOT02_OBJECTS,
    ACTORCAT_BG,
    FLAGS,
    OBJECT_SPOT02_OBJECTS,
    sizeof(BgSpot02Objects),
    (ActorFunc)BgSpot02Objects_Init,
    (ActorFunc)BgSpot02Objects_Destroy,
    (ActorFunc)BgSpot02Objects_Update,
    (ActorFunc)BgSpot02Objects_Draw,
};

GLOBAL_ASM("binary/BgSpot02Objects_Init.o")

GLOBAL_ASM("binary/BgSpot02Objects_Destroy.o")

GLOBAL_ASM("binary/BgSpot02Objects_Update.o")

GLOBAL_ASM("binary/BgSpot02Objects_Draw.o")
}
