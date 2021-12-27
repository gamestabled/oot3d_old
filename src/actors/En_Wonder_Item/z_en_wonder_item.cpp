extern "C" {
#include "z_en_wonder_item.hpp"

#define FLAGS 0x00000000

void EnWonderItem_Init(Actor* actor, GameState* state);
void EnWonderItem_Destroy(Actor* actor, GameState* state);
void EnWonderItem_Update(Actor* actor, GameState* state);

GLOBAL_ASM("binary/z_En_Wonder_Item.data.o")

/*
ActorInit En_Wonder_Item_InitVars = {
    ACTOR_EN_WONDER_ITEM,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(EnWonderItem),
    (ActorFunc)EnWonderItem_Init,
    (ActorFunc)EnWonderItem_Destroy,
    (ActorFunc)EnWonderItem_Update,
    NULL,
};
*/

GLOBAL_ASM("binary/EnWonderItem_Init.o")

GLOBAL_ASM("binary/EnWonderItem_Destroy.o")

GLOBAL_ASM("binary/EnWonderItem_Update.o")
}
