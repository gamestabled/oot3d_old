extern "C" {
#include "z_en_arow_trap.hpp"

#define FLAGS 0x00000010

void EnArowTrap_Init(Actor* actor, GameState* state);
void EnArowTrap_Destroy(Actor* actor, GameState* state);
void EnArowTrap_Update(Actor* actor, GameState* state);

ActorInit En_Arow_Trap_InitVars = {
    ACTOR_EN_AROW_TRAP,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(EnArowTrap),
    (ActorFunc)EnArowTrap_Init,
    (ActorFunc)EnArowTrap_Destroy,
    (ActorFunc)EnArowTrap_Update,
    NULL,
};

GLOBAL_ASM("binary/EnArowTrap_Init.o")

GLOBAL_ASM("binary/EnArowTrap_Destroy.o")

GLOBAL_ASM("binary/EnArowTrap_Update.o")
}
