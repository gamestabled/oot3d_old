extern "C" {
#include "z_oceff_wipe.hpp"

#define FLAGS 0x02000010

void OceffWipe_Init(Actor* actor, GameState* state);
void OceffWipe_Destroy(Actor* actor, GameState* state);
void OceffWipe_Update(Actor* actor, GameState* state);
void OceffWipe_Draw(Actor* actor, GameState* state);

GLOBAL_ASM("binary/z_Oceff_Wipe.data.o")

/*
ActorInit Oceff_Wipe_InitVars = {
    ACTOR_OCEFF_WIPE,
    ACTORCAT_ITEMACTION,
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(OceffWipe),
    (ActorFunc)OceffWipe_Init,
    (ActorFunc)OceffWipe_Destroy,
    (ActorFunc)OceffWipe_Update,
    (ActorFunc)OceffWipe_Draw,
};
*/

GLOBAL_ASM("binary/OceffWipe_Init.o")

GLOBAL_ASM("binary/OceffWipe_Destroy.o")

GLOBAL_ASM("binary/OceffWipe_Update.o")

GLOBAL_ASM("binary/OceffWipe_Draw.o")
}
