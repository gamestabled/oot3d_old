extern "C" {
#include "z_bg_mori_elevator.hpp"

#define FLAGS 0x80400010

void BgMoriElevator_Init(Actor* actor, GameState* state);
void BgMoriElevator_Destroy(Actor* actor, GameState* state);
void BgMoriElevator_Update(Actor* actor, GameState* state);

GLOBAL_ASM("binary/z_Bg_Mori_Elevator.data.o")

ActorInit Bg_Mori_Elevator_InitVars = {
    ACTOR_BG_MORI_ELEVATOR,
    ACTORCAT_BG,
    FLAGS,
    OBJECT_MORI_OBJECTS,
    sizeof(BgMoriElevator),
    (ActorFunc)BgMoriElevator_Init,
    (ActorFunc)BgMoriElevator_Destroy,
    (ActorFunc)BgMoriElevator_Update,
    NULL,
};

GLOBAL_ASM("binary/BgMoriElevator_Init.o")

GLOBAL_ASM("binary/BgMoriElevator_Destroy.o")

GLOBAL_ASM("binary/BgMoriElevator_Update.o")
}
