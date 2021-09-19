extern "C" {
#include "z_bg_jya_cobra.hpp"

#define FLAGS 0x80400010

void BgJyaCobra_Init(Actor* actor, GameState* state);
void BgJyaCobra_Destroy(Actor* actor, GameState* state);
void BgJyaCobra_Update(Actor* actor, GameState* state);
void BgJyaCobra_Draw(Actor* actor, GameState* state);

/*
ActorInit Bg_Jya_Cobra_InitVars = {
    ACTOR_BG_JYA_COBRA,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_JYA_OBJ,
    sizeof(BgJyaCobra),
    (ActorFunc)BgJyaCobra_Init,
    (ActorFunc)BgJyaCobra_Destroy,
    (ActorFunc)BgJyaCobra_Update,
    (ActorFunc)BgJyaCobra_Draw,
};
*/

#pragma GLOBAL_ASM("binary/BgJyaCobra_Init.o")

#pragma GLOBAL_ASM("binary/BgJyaCobra_Destroy.o")

#pragma GLOBAL_ASM("binary/BgJyaCobra_Update.o")

#pragma GLOBAL_ASM("binary/BgJyaCobra_Draw.o")
}
