extern "C" {
#include "z_en_po_desert.hpp"

#define FLAGS 0x00001090

void EnPoDesert_Init(Actor* actor, GameState* state);
void EnPoDesert_Destroy(Actor* actor, GameState* state);
void EnPoDesert_Update(Actor* actor, GameState* state);
void EnPoDesert_Draw(Actor* actor, GameState* state);

/*
ActorInit En_Po_Desert_InitVars = {
    ACTOR_EN_PO_DESERT,
    ACTORCAT_BG,
    FLAGS,
    OBJECT_PO_FIELD,
    sizeof(EnPoDesert),
    (ActorFunc)EnPoDesert_Init,
    (ActorFunc)EnPoDesert_Destroy,
    (ActorFunc)EnPoDesert_Update,
    (ActorFunc)EnPoDesert_Draw,
};
*/

GLOBAL_ASM("binary/EnPoDesert_Init.o")

GLOBAL_ASM("binary/EnPoDesert_Destroy.o")

GLOBAL_ASM("binary/EnPoDesert_Update.o")

GLOBAL_ASM("binary/EnPoDesert_Draw.o")
}
