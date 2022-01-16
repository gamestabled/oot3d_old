extern "C" {
#include "z_oceff_wipe3.hpp"

#define FLAGS 0x02000010

void OceffWipe3_Init(Actor* actor, GameState* state);
void OceffWipe3_Destroy(Actor* actor, GameState* state);
void OceffWipe3_Update(Actor* actor, GameState* state);
void OceffWipe3_Draw(Actor* actor, GameState* state);

ActorInit Oceff_Wipe3_InitVars = {
    ACTOR_OCEFF_WIPE3,
    ACTORCAT_ITEMACTION,
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(OceffWipe3),
    (ActorFunc)OceffWipe3_Init,
    (ActorFunc)OceffWipe3_Destroy,
    (ActorFunc)OceffWipe3_Update,
    (ActorFunc)OceffWipe3_Draw,
};

GLOBAL_ASM("binary/OceffWipe3_Init.o")

GLOBAL_ASM("binary/OceffWipe3_Destroy.o")

GLOBAL_ASM("binary/OceffWipe3_Update.o")

GLOBAL_ASM("binary/OceffWipe3_Draw.o")
}
