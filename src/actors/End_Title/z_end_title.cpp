extern "C" {
#include "z_end_title.hpp"

#define FLAGS 0x00000030

void EndTitle_Init(Actor* actor, GameState* state);
void EndTitle_Destroy(Actor* actor, GameState* state);
void EndTitle_Update(Actor* actor, GameState* state);
void EndTitle_Draw(Actor* actor, GameState* state);

GLOBAL_ASM("binary/z_End_Title.data.o")

ActorInit End_Title_InitVars = {
    ACTOR_END_TITLE,
    ACTORCAT_ITEMACTION,
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(EndTitle),
    (ActorFunc)EndTitle_Init,
    (ActorFunc)EndTitle_Destroy,
    (ActorFunc)EndTitle_Update,
    (ActorFunc)EndTitle_Draw,
};

GLOBAL_ASM("binary/EndTitle_Init.o")

GLOBAL_ASM("binary/EndTitle_Destroy.o")

GLOBAL_ASM("binary/EndTitle_Update.o")

GLOBAL_ASM("binary/EndTitle_Draw.o")
}
