extern "C" {
#include "z_en_tk.hpp"

#define FLAGS 0x00000009

void EnTk_Init(Actor* actor, GameState* state);
void EnTk_Destroy(Actor* actor, GameState* state);
void EnTk_Update(Actor* actor, GameState* state);
void EnTk_Draw(Actor* actor, GameState* state);

GLOBAL_ASM("binary/z_En_Tk.data.o")

/*
ActorInit En_Tk_InitVars = {
    ACTOR_EN_TK,
    ACTORCAT_NPC,
    FLAGS,
    OBJECT_TK,
    sizeof(EnTk),
    (ActorFunc)EnTk_Init,
    (ActorFunc)EnTk_Destroy,
    (ActorFunc)EnTk_Update,
    (ActorFunc)EnTk_Draw,
};
*/

GLOBAL_ASM("binary/EnTk_Init.o")

GLOBAL_ASM("binary/EnTk_Destroy.o")

GLOBAL_ASM("binary/EnTk_Update.o")

GLOBAL_ASM("binary/EnTk_Draw.o")
}
