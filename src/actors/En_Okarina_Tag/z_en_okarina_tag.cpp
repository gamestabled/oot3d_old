extern "C" {
#include "z_en_okarina_tag.hpp"

#define FLAGS 0x02000010

void EnOkarinaTag_Init(Actor* actor, GameState* state);
void EnOkarinaTag_Destroy(Actor* actor, GameState* state);
void EnOkarinaTag_Update(Actor* actor, GameState* state);

GLOBAL_ASM("binary/z_En_Okarina_Tag.data.o")

/*
ActorInit En_Okarina_Tag_InitVars = {
    ACTOR_EN_OKARINA_TAG,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(EnOkarinaTag),
    (ActorFunc)EnOkarinaTag_Init,
    (ActorFunc)EnOkarinaTag_Destroy,
    (ActorFunc)EnOkarinaTag_Update,
    NULL,
};
*/

GLOBAL_ASM("binary/EnOkarinaTag_Init.o")

GLOBAL_ASM("binary/EnOkarinaTag_Destroy.o")

GLOBAL_ASM("binary/EnOkarinaTag_Update.o")
}
