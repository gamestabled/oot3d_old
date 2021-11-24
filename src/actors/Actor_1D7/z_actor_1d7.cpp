extern "C" {
#include "z_actor_1d7.hpp"

#define FLAGS 0x80000000

void Actor1D7_Init(Actor* actor, GameState* state);
void Actor1D7_Destroy(Actor* actor, GameState* state);
void Actor1D7_Update(Actor* actor, GameState* state);
void Actor1D7_Draw(Actor* actor, GameState* state);

/*
ActorInit Actor_1D7_InitVars = {
    ACTOR_1D7,
    ACTORCAT_BG,
    FLAGS,
    OBJECT_YDAN_OBJECTS,
    sizeof(Actor1D7),
    (ActorFunc)Actor1D7_Init,
    (ActorFunc)Actor1D7_Destroy,
    (ActorFunc)Actor1D7_Update,
    (ActorFunc)Actor1D7_Draw,
};
*/

GLOBAL_ASM("binary/Actor1D7_Init.o")

GLOBAL_ASM("binary/Actor1D7_Destroy.o")

GLOBAL_ASM("binary/Actor1D7_Update.o")

GLOBAL_ASM("binary/Actor1D7_Draw.o")
}
