extern "C" {
#include "z_bg_bdan_objects.hpp"

#define FLAGS 0x00400010

void BgBdanObjects_Init(Actor* actor, GameState* state);
void BgBdanObjects_Destroy(Actor* actor, GameState* state);
void BgBdanObjects_Update(Actor* actor, GameState* state);
void BgBdanObjects_Draw(Actor* actor, GameState* state);

GLOBAL_ASM("binary/z_Bg_Bdan_Objects.data.o")

ActorInit Bg_Bdan_Objects_InitVars = {
    ACTOR_BG_BDAN_OBJECTS,
    ACTORCAT_BG,
    FLAGS,
    OBJECT_BDAN_OBJECTS,
    sizeof(BgBdanObjects),
    (ActorFunc)BgBdanObjects_Init,
    (ActorFunc)BgBdanObjects_Destroy,
    (ActorFunc)BgBdanObjects_Update,
    (ActorFunc)BgBdanObjects_Draw,
};

GLOBAL_ASM("binary/BgBdanObjects_Init.o")

GLOBAL_ASM("binary/BgBdanObjects_Destroy.o")

GLOBAL_ASM("binary/BgBdanObjects_Update.o")

GLOBAL_ASM("binary/BgBdanObjects_Draw.o")
}
