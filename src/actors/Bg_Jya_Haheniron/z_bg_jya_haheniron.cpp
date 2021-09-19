extern "C" {
#include "z_bg_jya_haheniron.hpp"

#define FLAGS 0x80400010

void BgJyaHaheniron_Init(Actor* actor, GameState* state);
void BgJyaHaheniron_Destroy(Actor* actor, GameState* state);
void BgJyaHaheniron_Update(Actor* actor, GameState* state);
void BgJyaHaheniron_Draw(Actor* actor, GameState* state);

/*
ActorInit Bg_Jya_Haheniron_InitVars = {
    ACTOR_BG_JYA_HAHENIRON,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_JYA_IRON,
    sizeof(BgJyaHaheniron),
    (ActorFunc)BgJyaHaheniron_Init,
    (ActorFunc)BgJyaHaheniron_Destroy,
    (ActorFunc)BgJyaHaheniron_Update,
    (ActorFunc)BgJyaHaheniron_Draw,
};
*/

#pragma GLOBAL_ASM("binary/BgJyaHaheniron_Init.o")

#pragma GLOBAL_ASM("binary/BgJyaHaheniron_Destroy.o")

#pragma GLOBAL_ASM("binary/BgJyaHaheniron_Update.o")

#pragma GLOBAL_ASM("binary/BgJyaHaheniron_Draw.o")
}
