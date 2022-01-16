extern "C" {
#include "z_en_torch2.hpp"

#define FLAGS 0x00000035

void EnTorch2_Init(Actor* actor, GameState* state);
void EnTorch2_Destroy(Actor* actor, GameState* state);
void EnTorch2_Update(Actor* actor, GameState* state);
void EnTorch2_Draw(Actor* actor, GameState* state);

GLOBAL_ASM("binary/z_En_Torch2.data.o")

ActorInit En_Torch2_InitVars = {
    ACTOR_EN_TORCH2,
    ACTORCAT_BOSS,
    FLAGS,
    OBJECT_TORCH2,
    sizeof(EnTorch2),
    (ActorFunc)EnTorch2_Init,
    (ActorFunc)EnTorch2_Destroy,
    (ActorFunc)EnTorch2_Update,
    (ActorFunc)EnTorch2_Draw,
};

GLOBAL_ASM("binary/EnTorch2_Init.o")

GLOBAL_ASM("binary/EnTorch2_Destroy.o")

GLOBAL_ASM("binary/EnTorch2_Update.o")

GLOBAL_ASM("binary/EnTorch2_Draw.o")
}
