extern "C" {
#include "z_en_xc.hpp"

#define FLAGS 0x00000010

void EnXc_Init(Actor* actor, GameState* state);
void EnXc_Destroy(Actor* actor, GameState* state);
void EnXc_Update(Actor* actor, GameState* state);
void EnXc_Draw(Actor* actor, GameState* state);

GLOBAL_ASM("binary/z_En_Xc.data.o")

ActorInit En_Xc_InitVars = {
    ACTOR_EN_XC,
    ACTORCAT_NPC,
    FLAGS,
    OBJECT_XC,
    sizeof(EnXc),
    (ActorFunc)EnXc_Init,
    (ActorFunc)EnXc_Destroy,
    (ActorFunc)EnXc_Update,
    (ActorFunc)EnXc_Draw,
};

GLOBAL_ASM("binary/EnXc_Init.o")

GLOBAL_ASM("binary/EnXc_Destroy.o")

GLOBAL_ASM("binary/EnXc_Update.o")

GLOBAL_ASM("binary/EnXc_Draw.o")
}
