extern "C" {
#include "z_en_kanban.hpp"

#define FLAGS 0x80000019

void EnKanban_Init(Actor* actor, GameState* state);
void EnKanban_Destroy(Actor* actor, GameState* state);
void EnKanban_Update(Actor* actor, GameState* state);
void EnKanban_Draw(Actor* actor, GameState* state);

/*
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
*/

#pragma GLOBAL_ASM("binary/EnKanban_Init.o")

#pragma GLOBAL_ASM("binary/EnKanban_Destroy.o")

#pragma GLOBAL_ASM("binary/EnKanban_Update.o")

#pragma GLOBAL_ASM("binary/EnKanban_Draw.o")
}
