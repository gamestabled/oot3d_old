extern "C" {
#include "z_bg_jya_bigmirror.hpp"

#define FLAGS 0x80400030

void BgJyaBigmirror_Init(Actor* actor, GameState* state);
void BgJyaBigmirror_Destroy(Actor* actor, GameState* state);
void BgJyaBigmirror_Update(Actor* actor, GameState* state);
void BgJyaBigmirror_Draw(Actor* actor, GameState* state);

/*
ActorInit Bg_Jya_Bigmirror_InitVars = {
    ACTOR_BG_JYA_BIGMIRROR,
    ACTORCAT_BG,
    FLAGS,
    OBJECT_JYA_OBJ,
    sizeof(BgJyaBigmirror),
    (ActorFunc)BgJyaBigmirror_Init,
    (ActorFunc)BgJyaBigmirror_Destroy,
    (ActorFunc)BgJyaBigmirror_Update,
    (ActorFunc)BgJyaBigmirror_Draw,
};
*/

#pragma GLOBAL_ASM("binary/BgJyaBigmirror_Init.o")

#pragma GLOBAL_ASM("binary/BgJyaBigmirror_Destroy.o")

#pragma GLOBAL_ASM("binary/BgJyaBigmirror_Update.o")

#pragma GLOBAL_ASM("binary/BgJyaBigmirror_Draw.o")
}
