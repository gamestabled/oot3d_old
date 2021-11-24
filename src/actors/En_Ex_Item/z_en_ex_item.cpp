extern "C" {
#include "z_en_ex_item.hpp"

#define FLAGS 0x00000030

void EnExItem_Init(Actor* actor, GameState* state);
void EnExItem_Destroy(Actor* actor, GameState* state);
void EnExItem_Update(Actor* actor, GameState* state);
void EnExItem_Draw(Actor* actor, GameState* state);

/*
ActorInit En_Ex_Item_InitVars = {
    ACTOR_EN_EX_ITEM,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(EnExItem),
    (ActorFunc)EnExItem_Init,
    (ActorFunc)EnExItem_Destroy,
    (ActorFunc)EnExItem_Update,
    (ActorFunc)EnExItem_Draw,
};
*/

GLOBAL_ASM("binary/EnExItem_Init.o")

GLOBAL_ASM("binary/EnExItem_Destroy.o")

GLOBAL_ASM("binary/EnExItem_Update.o")

GLOBAL_ASM("binary/EnExItem_Draw.o")
}
