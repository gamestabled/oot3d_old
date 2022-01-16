extern "C" {
#include "z_oceff_wipe2.hpp"

#define FLAGS 0x02000010

void OceffWipe2_Init(Actor* actor, GameState* state);
void OceffWipe2_Destroy(Actor* actor, GameState* state);
void OceffWipe2_Update(Actor* actor, GameState* state);
void OceffWipe2_Draw(Actor* actor, GameState* state);

ActorInit Oceff_Wipe2_InitVars = {
    ACTOR_OCEFF_WIPE2,
    ACTORCAT_ITEMACTION,
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(OceffWipe2),
    (ActorFunc)OceffWipe2_Init,
    (ActorFunc)OceffWipe2_Destroy,
    (ActorFunc)OceffWipe2_Update,
    (ActorFunc)OceffWipe2_Draw,
};

GLOBAL_ASM("binary/OceffWipe2_Init.o")

GLOBAL_ASM("binary/OceffWipe2_Destroy.o")

GLOBAL_ASM("binary/OceffWipe2_Update.o")

GLOBAL_ASM("binary/OceffWipe2_Draw.o")
}
