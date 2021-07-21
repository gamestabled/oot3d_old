extern "C" {
#include "z_bg_jya_goroiwa.hpp"

#define FLAGS 0x80000010

void BgJyaGoroiwa_Init(Actor* actor, GameState* state);
void BgJyaGoroiwa_Destroy(Actor* actor, GameState* state);
void BgJyaGoroiwa_Update(Actor* actor, GameState* state);
void BgJyaGoroiwa_Draw(Actor* actor, GameState* state);

/*
ActorInit Bg_Jya_Goroiwa_InitVars = {
    ACTOR_BG_JYA_GOROIWA,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_GOROIWA,
    sizeof(BgJyaGoroiwa),
    (ActorFunc)BgJyaGoroiwa_Init,
    (ActorFunc)BgJyaGoroiwa_Destroy,
    (ActorFunc)BgJyaGoroiwa_Update,
    (ActorFunc)BgJyaGoroiwa_Draw,
};
*/
}
