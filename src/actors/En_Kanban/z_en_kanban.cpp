extern "C" {
#include "z_en_kanban.hpp"

#define FLAGS 0x80000019

void EnKanban_Init(Actor* actor, GameState* state);
void EnKanban_Destroy(Actor* actor, GameState* state);
void EnKanban_Update(Actor* actor, GameState* state);
void EnKanban_Draw(Actor* actor, GameState* state);

GLOBAL_ASM("binary/z_En_Kanban.data.o")

ActorInit En_Kanban_InitVars = {
    ACTOR_EN_KANBAN,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_KANBAN,
    sizeof(EnKanban),
    (ActorFunc)EnKanban_Init,
    (ActorFunc)EnKanban_Destroy,
    (ActorFunc)EnKanban_Update,
    (ActorFunc)EnKanban_Draw,
};

GLOBAL_ASM("binary/EnKanban_Init.o")

GLOBAL_ASM("binary/EnKanban_Destroy.o")

GLOBAL_ASM("binary/EnKanban_Update.o")

GLOBAL_ASM("binary/EnKanban_Draw.o")
}
