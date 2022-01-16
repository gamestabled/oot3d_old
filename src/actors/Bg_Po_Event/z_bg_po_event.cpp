extern "C" {
#include "z_bg_po_event.hpp"

#define FLAGS 0x00400000

void BgPoEvent_Init(Actor* actor, GameState* state);
void BgPoEvent_Destroy(Actor* actor, GameState* state);
void BgPoEvent_Update(Actor* actor, GameState* state);
void BgPoEvent_Draw(Actor* actor, GameState* state);

GLOBAL_ASM("binary/z_Bg_Po_Event.data.o")

ActorInit Bg_Po_Event_InitVars = {
    ACTOR_BG_PO_EVENT,
    ACTORCAT_BG,
    FLAGS,
    OBJECT_PO_SISTERS,
    sizeof(BgPoEvent),
    (ActorFunc)BgPoEvent_Init,
    (ActorFunc)BgPoEvent_Destroy,
    (ActorFunc)BgPoEvent_Update,
    (ActorFunc)BgPoEvent_Draw,
};

GLOBAL_ASM("binary/BgPoEvent_Init.o")

GLOBAL_ASM("binary/BgPoEvent_Destroy.o")

GLOBAL_ASM("binary/BgPoEvent_Update.o")

GLOBAL_ASM("binary/BgPoEvent_Draw.o")
}
