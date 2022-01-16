extern "C" {
#include "z_en_vali.hpp"

#define FLAGS 0x00001015

void EnVali_Init(Actor* actor, GameState* state);
void EnVali_Destroy(Actor* actor, GameState* state);
void EnVali_Update(Actor* actor, GameState* state);
void EnVali_Draw(Actor* actor, GameState* state);

GLOBAL_ASM("binary/z_En_Vali.data.o")

ActorInit En_Vali_InitVars = {
    ACTOR_EN_VALI,
    ACTORCAT_ENEMY,
    FLAGS,
    OBJECT_VALI,
    sizeof(EnVali),
    (ActorFunc)EnVali_Init,
    (ActorFunc)EnVali_Destroy,
    (ActorFunc)EnVali_Update,
    (ActorFunc)EnVali_Draw,
};

GLOBAL_ASM("binary/EnVali_Init.o")

GLOBAL_ASM("binary/EnVali_Destroy.o")

GLOBAL_ASM("binary/EnVali_Update.o")

GLOBAL_ASM("binary/EnVali_Draw.o")
}
