extern "C" {
#include "z_en_wonder_talk.hpp"

#define FLAGS 0x88000009

void EnWonderTalk_Init(Actor* actor, GameState* state);
void EnWonderTalk_Destroy(Actor* actor, GameState* state);
void EnWonderTalk_Update(Actor* actor, GameState* state);

ActorInit En_Wonder_Talk_InitVars = {
    ACTOR_EN_WONDER_TALK,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(EnWonderTalk),
    (ActorFunc)EnWonderTalk_Init,
    (ActorFunc)EnWonderTalk_Destroy,
    (ActorFunc)EnWonderTalk_Update,
    NULL,
};

GLOBAL_ASM("binary/EnWonderTalk_Init.o")

GLOBAL_ASM("binary/EnWonderTalk_Destroy.o")

GLOBAL_ASM("binary/EnWonderTalk_Update.o")
}
