extern "C" {
#include "z_item_etcetera.hpp"

#define FLAGS 0x00000010

void ItemEtcetera_Init(Actor* actor, GameState* state);
void ItemEtcetera_Destroy(Actor* actor, GameState* state);
void ItemEtcetera_Update(Actor* actor, GameState* state);

/*
ActorInit Item_Etcetera_InitVars = {
    ACTOR_ITEM_ETCETERA,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(ItemEtcetera),
    (ActorFunc)ItemEtcetera_Init,
    (ActorFunc)ItemEtcetera_Destroy,
    (ActorFunc)ItemEtcetera_Update,
    (ActorFunc)NULL,
};
*/

#pragma GLOBAL_ASM("binary/ItemEtcetera_Init.o")

#pragma GLOBAL_ASM("binary/ItemEtcetera_Destroy.o")

#pragma GLOBAL_ASM("binary/ItemEtcetera_Update.o")
}
