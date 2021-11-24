extern "C" {
#include "z_en_js.hpp"

#define FLAGS 0x00000009

void EnJs_Init(Actor* actor, GameState* state);
void EnJs_Destroy(Actor* actor, GameState* state);
void EnJs_Update(Actor* actor, GameState* state);
void EnJs_Draw(Actor* actor, GameState* state);

/*
ActorInit En_Js_InitVars = {
    ACTOR_EN_JS,
    ACTORCAT_NPC,
    FLAGS,
    OBJECT_JS,
    sizeof(EnJs),
    (ActorFunc)EnJs_Init,
    (ActorFunc)EnJs_Destroy,
    (ActorFunc)EnJs_Update,
    (ActorFunc)EnJs_Draw,
};
*/

GLOBAL_ASM("binary/EnJs_Init.o")

GLOBAL_ASM("binary/EnJs_Destroy.o")

GLOBAL_ASM("binary/EnJs_Update.o")

GLOBAL_ASM("binary/EnJs_Draw.o")
}
