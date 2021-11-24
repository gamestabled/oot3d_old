extern "C" {
#include "z_en_po_relay.hpp"

#define FLAGS 0x00011019

void EnPoRelay_Init(Actor* actor, GameState* state);
void EnPoRelay_Destroy(Actor* actor, GameState* state);
void EnPoRelay_Update(Actor* actor, GameState* state);
void EnPoRelay_Draw(Actor* actor, GameState* state);

/*
ActorInit En_Po_Relay_InitVars = {
    ACTOR_EN_PO_RELAY,
    ACTORCAT_NPC,
    FLAGS,
    OBJECT_TK,
    sizeof(EnPoRelay),
    (ActorFunc)EnPoRelay_Init,
    (ActorFunc)EnPoRelay_Destroy,
    (ActorFunc)EnPoRelay_Update,
    (ActorFunc)EnPoRelay_Draw,
};
*/

GLOBAL_ASM("binary/EnPoRelay_Init.o")

GLOBAL_ASM("binary/EnPoRelay_Destroy.o")

GLOBAL_ASM("binary/EnPoRelay_Update.o")

GLOBAL_ASM("binary/EnPoRelay_Draw.o")
}
