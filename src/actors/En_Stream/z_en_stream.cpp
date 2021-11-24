extern "C" {
#include "z_en_stream.hpp"

#define FLAGS 0x80400010

void EnStream_Init(Actor* actor, GameState* state);
void EnStream_Destroy(Actor* actor, GameState* state);
void EnStream_Update(Actor* actor, GameState* state);
void EnStream_Draw(Actor* actor, GameState* state);

/*
ActorInit En_Stream_InitVars = {
    ACTOR_EN_STREAM,
    ACTORCAT_BG,
    FLAGS,
    OBJECT_STREAM,
    sizeof(EnStream),
    (ActorFunc)EnStream_Init,
    (ActorFunc)EnStream_Destroy,
    (ActorFunc)EnStream_Update,
    (ActorFunc)EnStream_Draw,
};
*/

GLOBAL_ASM("binary/EnStream_Init.o")

GLOBAL_ASM("binary/EnStream_Destroy.o")

GLOBAL_ASM("binary/EnStream_Update.o")

GLOBAL_ASM("binary/EnStream_Draw.o")
}
