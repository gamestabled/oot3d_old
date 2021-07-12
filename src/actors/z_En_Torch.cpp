extern "C" {
#include "z_En_Torch.hpp"

#include "z3Dobject.hpp"
#include "functions.hpp"
#include "stddef.hpp"

#define FLAGS 0x00000000

#define SELF ((EnTorch*)super)

void EnTorch_Init(Actor* super, GameState* globalCtx);

ActorInit EnTorch_InitVars = {
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

// void EnTorch_Init(Actor* super, GameState* state) {
//     EnTorch* self = SELF;
//     GlobalContext* globalCtx = (GlobalContext*)state;

//     s8 returnData = gSaveContext.respawn[RESPAWN_MODE_RETURN].data;

//     /* Spawn chest with desired contents.
//        Contents are passed to en_torch from grotto params via Save Context. */
//     Actor_Spawn(&globalCtx->actorCtx, globalCtx, ACTOR_EN_BOX, self->actor.world.pos.x, self->actor.world.pos.y,
//                 self->actor.world.pos.z, 0, self->actor.shape.rot.y, 0,
//                 (sChestContents[(returnData >> 0x5) & 0x7] << 0x5) | 0x5000 | (returnData & 0x1F), 1);

//     Actor_Kill(&self->actor);
// }

}
