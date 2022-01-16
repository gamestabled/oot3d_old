extern "C" {
#include "z_en_sw.hpp"

#define FLAGS 0x00000035

void EnSw_Init(Actor* actor, GameState* state);
void EnSw_Destroy(Actor* actor, GameState* state);
void EnSw_Update(Actor* actor, GameState* state);
void EnSw_Draw(Actor* actor, GameState* state);

GLOBAL_ASM("binary/z_En_Sw.data_0052F258.o")
GLOBAL_ASM("binary/z_En_Sw.data_0052F300.o")

ActorInit En_Sw_InitVars = {
    ACTOR_EN_SW,
    ACTORCAT_NPC,
    FLAGS,
    OBJECT_ST,
    sizeof(EnSw),
    (ActorFunc)EnSw_Init,
    (ActorFunc)EnSw_Destroy,
    (ActorFunc)EnSw_Update,
    (ActorFunc)EnSw_Draw,
};

GLOBAL_ASM("binary/EnSw_Init.o")

GLOBAL_ASM("binary/EnSw_Destroy.o")

GLOBAL_ASM("binary/EnSw_Update.o")

GLOBAL_ASM("binary/EnSw_Draw.o")
}
