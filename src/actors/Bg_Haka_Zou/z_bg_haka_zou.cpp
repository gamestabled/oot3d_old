extern "C" {
#include "z_bg_haka_zou.hpp"

#define FLAGS 0x00400010

void BgHakaZou_Init(Actor* actor, GameState* state);
void BgHakaZou_Destroy(Actor* actor, GameState* state);
void BgHakaZou_Update(Actor* actor, GameState* state);

GLOBAL_ASM("binary/z_Bg_Haka_Zou.data.o")

/*
ActorInit Bg_Haka_Zou_InitVars = {
    ACTOR_BG_HAKA_ZOU,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(BgHakaZou),
    (ActorFunc)BgHakaZou_Init,
    (ActorFunc)BgHakaZou_Destroy,
    (ActorFunc)BgHakaZou_Update,
    (ActorFunc)NULL,
};
*/

GLOBAL_ASM("binary/BgHakaZou_Init.o")

GLOBAL_ASM("binary/BgHakaZou_Destroy.o")

GLOBAL_ASM("binary/BgHakaZou_Update.o")
}
