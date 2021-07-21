extern "C" {
#include "z_bg_hidan_hamstep.hpp"

#define FLAGS 0x00400000

void BgHidanHamstep_Init(Actor* actor, GameState* state);
void BgHidanHamstep_Destroy(Actor* actor, GameState* state);
void BgHidanHamstep_Update(Actor* actor, GameState* state);
void BgHidanHamstep_Draw(Actor* actor, GameState* state);

/*
ActorInit Bg_Hidan_Hamstep_InitVars = {
    ACTOR_BG_HIDAN_HAMSTEP,
    ACTORCAT_BG,
    FLAGS,
    OBJECT_HIDAN_OBJECTS,
    sizeof(BgHidanHamstep),
    (ActorFunc)BgHidanHamstep_Init,
    (ActorFunc)BgHidanHamstep_Destroy,
    (ActorFunc)BgHidanHamstep_Update,
    (ActorFunc)BgHidanHamstep_Draw,
};
*/
}
