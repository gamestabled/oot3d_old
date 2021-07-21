extern "C" {
#include "z_bg_jya_bombchuiwa.hpp"

#define FLAGS 0x00400001

void BgJyaBombchuiwa_Init(Actor* actor, GameState* state);
void BgJyaBombchuiwa_Destroy(Actor* actor, GameState* state);
void BgJyaBombchuiwa_Update(Actor* actor, GameState* state);
void BgJyaBombchuiwa_Draw(Actor* actor, GameState* state);

/*
ActorInit Bg_Jya_Bombchuiwa_InitVars = {
    ACTOR_BG_JYA_BOMBCHUIWA,
    ACTORCAT_BG,
    FLAGS,
    OBJECT_JYA_OBJ,
    sizeof(BgJyaBombchuiwa),
    (ActorFunc)BgJyaBombchuiwa_Init,
    (ActorFunc)BgJyaBombchuiwa_Destroy,
    (ActorFunc)BgJyaBombchuiwa_Update,
    (ActorFunc)BgJyaBombchuiwa_Draw,
};
*/
}
