extern "C" {
#include "z_item_b_heart.hpp"

#define FLAGS 0x00000000

void ItemBHeart_Init(Actor* actor, GameState* state);
void ItemBHeart_Destroy(Actor* actor, GameState* state);
void ItemBHeart_Update(Actor* actor, GameState* state);
void ItemBHeart_Draw(Actor* actor, GameState* state);

/*
ActorInit Item_B_Heart_InitVars = {
    ACTOR_ITEM_B_HEART,
    ACTORCAT_MISC,
    FLAGS,
    OBJECT_GI_HEARTS,
    sizeof(ItemBHeart),
    (ActorFunc)ItemBHeart_Init,
    (ActorFunc)ItemBHeart_Destroy,
    (ActorFunc)ItemBHeart_Update,
    (ActorFunc)ItemBHeart_Draw,
};
*/
}
