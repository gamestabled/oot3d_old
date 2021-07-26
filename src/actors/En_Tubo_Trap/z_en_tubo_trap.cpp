extern "C" {
#include "z_en_tubo_trap.hpp"

#define FLAGS 0x80000010

void EnTuboTrap_Init(Actor* actor, GameState* state);
void EnTuboTrap_Destroy(Actor* actor, GameState* state);
void EnTuboTrap_Update(Actor* actor, GameState* state);
void EnTuboTrap_Draw(Actor* actor, GameState* state);

/*
ActorInit En_Tubo_Trap_InitVars = {
    ACTOR_EN_TUBO_TRAP,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_GAMEPLAY_DANGEON_KEEP,
    sizeof(EnTuboTrap),
    (ActorFunc)EnTuboTrap_Init,
    (ActorFunc)EnTuboTrap_Destroy,
    (ActorFunc)EnTuboTrap_Update,
    (ActorFunc)EnTuboTrap_Draw,
};
*/
}