extern "C" {
#include "z_en_torch.hpp"

#define FLAGS 0x00000000

void EnTorch_Init(Actor* actor, GameState* state);

ActorInit En_Torch_InitVars = {
    ACTOR_EN_TORCH,
    ACTORCAT_ITEMACTION,
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(EnTorch),
    (ActorFunc)EnTorch_Init,
    (ActorFunc)NULL,
    (ActorFunc)NULL,
    (ActorFunc)NULL,
};

u8 sChestContents[] = {
    GI_RUPEE_BLUE, GI_RUPEE_RED, GI_RUPEE_GOLD, GI_BOMBS_20, GI_BOMBS_1, GI_BOMBS_1, GI_BOMBS_1, GI_BOMBS_1,
};
}
