extern "C" {
#include "z_en_clear_tag.hpp"

#define FLAGS 0x00000035

void EnClearTag_Init(Actor* actor, GameState* state);
void EnClearTag_Destroy(Actor* actor, GameState* state);
void EnClearTag_Update(Actor* actor, GameState* state);
void EnClearTag_Draw(Actor* actor, GameState* state);

GLOBAL_ASM("binary/z_En_Clear_Tag.data.o")

/*
ActorInit En_Clear_Tag_InitVars = {
    ACTOR_EN_CLEAR_TAG,
    ACTORCAT_BOSS,
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(EnClearTag),
    (ActorFunc)EnClearTag_Init,
    (ActorFunc)EnClearTag_Destroy,
    (ActorFunc)EnClearTag_Update,
    (ActorFunc)EnClearTag_Draw,
};
*/

GLOBAL_ASM("binary/EnClearTag_Init.o")

GLOBAL_ASM("binary/EnClearTag_Destroy.o")

GLOBAL_ASM("binary/EnClearTag_Update.o")

GLOBAL_ASM("binary/EnClearTag_Draw.o")
}
