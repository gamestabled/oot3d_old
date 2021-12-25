extern "C" {
#include "z_item_shield.hpp"

#define FLAGS 0x00000010

void ItemShield_Init(Actor* actor, GameState* state);
void ItemShield_Destroy(Actor* actor, GameState* state);
void ItemShield_Update(Actor* actor, GameState* state);
void ItemShield_Draw(Actor* actor, GameState* state);

GLOBAL_ASM("binary/z_Item_Shield.data.o")

/*
ActorInit Item_Shield_InitVars = {
    ACTOR_ITEM_SHIELD,
    ACTORCAT_ITEMACTION,
    FLAGS,
    OBJECT_LINK_CHILD,
    sizeof(ItemShield),
    (ActorFunc)ItemShield_Init,
    (ActorFunc)ItemShield_Destroy,
    (ActorFunc)ItemShield_Update,
    (ActorFunc)ItemShield_Draw,
};
*/

GLOBAL_ASM("binary/ItemShield_Init.o")

GLOBAL_ASM("binary/ItemShield_Destroy.o")

GLOBAL_ASM("binary/ItemShield_Update.o")

GLOBAL_ASM("binary/ItemShield_Draw.o")
}
