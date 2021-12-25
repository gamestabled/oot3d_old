extern "C" {
#include "z_en_po_sisters.hpp"

#define FLAGS 0x00005215

void EnPoSisters_Init(Actor* actor, GameState* state);
void EnPoSisters_Destroy(Actor* actor, GameState* state);
void EnPoSisters_Update(Actor* actor, GameState* state);
void EnPoSisters_Draw(Actor* actor, GameState* state);

GLOBAL_ASM("binary/z_En_Po_Sisters.data.o")

/*
ActorInit En_Po_Sisters_InitVars = {
    ACTOR_EN_PO_SISTERS,
    ACTORCAT_ENEMY,
    FLAGS,
    OBJECT_PO_SISTERS,
    sizeof(EnPoSisters),
    (ActorFunc)EnPoSisters_Init,
    (ActorFunc)EnPoSisters_Destroy,
    (ActorFunc)EnPoSisters_Update,
    (ActorFunc)EnPoSisters_Draw,
};
*/

GLOBAL_ASM("binary/EnPoSisters_Init.o")

GLOBAL_ASM("binary/EnPoSisters_Destroy.o")

GLOBAL_ASM("binary/EnPoSisters_Update.o")

GLOBAL_ASM("binary/EnPoSisters_Draw.o")
}
