extern "C" {
#include "z_en_gs.hpp"

#define FLAGS 0x02000009

void EnGs_Init(Actor* actor, GameState* state);
void EnGs_Destroy(Actor* actor, GameState* state);
void EnGs_Update(Actor* actor, GameState* state);
void EnGs_Draw(Actor* actor, GameState* state);

GLOBAL_ASM("binary/z_En_Gs.data.o")

ActorInit En_Gs_InitVars = {
    ACTOR_EN_GS,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_GS,
    sizeof(EnGs),
    (ActorFunc)EnGs_Init,
    (ActorFunc)EnGs_Destroy,
    (ActorFunc)EnGs_Update,
    (ActorFunc)EnGs_Draw,
};

GLOBAL_ASM("binary/EnGs_Init.o")

GLOBAL_ASM("binary/EnGs_Destroy.o")

GLOBAL_ASM("binary/EnGs_Update.o")

GLOBAL_ASM("binary/EnGs_Draw.o")
}
