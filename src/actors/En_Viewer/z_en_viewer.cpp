extern "C" {
#include "z_en_viewer.hpp"

#define FLAGS 0x00000010

void EnViewer_Init(Actor* actor, GameState* state);
void EnViewer_Destroy(Actor* actor, GameState* state);
void EnViewer_Update(Actor* actor, GameState* state);
void EnViewer_Draw(Actor* actor, GameState* state);

GLOBAL_ASM("binary/z_En_Viewer.data.o")

ActorInit En_Viewer_InitVars = {
    ACTOR_EN_VIEWER,
    ACTORCAT_ITEMACTION,
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(EnViewer),
    (ActorFunc)EnViewer_Init,
    (ActorFunc)EnViewer_Destroy,
    (ActorFunc)EnViewer_Update,
    (ActorFunc)EnViewer_Draw,
};

GLOBAL_ASM("binary/EnViewer_Init.o")

GLOBAL_ASM("binary/EnViewer_Destroy.o")

GLOBAL_ASM("binary/EnViewer_Update.o")

GLOBAL_ASM("binary/EnViewer_Draw.o")
}
