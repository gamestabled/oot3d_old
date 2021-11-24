extern "C" {
#include "z_item_ocarina.hpp"

#define FLAGS 0x00000010

void ItemOcarina_Init(Actor* actor, GameState* state);
void ItemOcarina_Destroy(Actor* actor, GameState* state);
void ItemOcarina_Update(Actor* actor, GameState* state);
void ItemOcarina_Draw(Actor* actor, GameState* state);

/*
ActorInit Item_Ocarina_InitVars = {
    ACTOR_ITEM_OCARINA,
    ACTORCAT_ITEMACTION,
    FLAGS,
    OBJECT_GI_OCARINA,
    sizeof(ItemOcarina),
    (ActorFunc)ItemOcarina_Init,
    (ActorFunc)ItemOcarina_Destroy,
    (ActorFunc)ItemOcarina_Update,
    (ActorFunc)ItemOcarina_Draw,
};
*/

GLOBAL_ASM("binary/ItemOcarina_Init.o")

GLOBAL_ASM("binary/ItemOcarina_Destroy.o")

GLOBAL_ASM("binary/ItemOcarina_Update.o")

GLOBAL_ASM("binary/ItemOcarina_Draw.o")
}
