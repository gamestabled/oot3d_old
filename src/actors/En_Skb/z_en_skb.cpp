extern "C" {
#include "z_en_skb.hpp"

#define FLAGS 0x00000015

void EnSkb_Init(Actor* actor, GameState* state);
void EnSkb_Destroy(Actor* actor, GameState* state);
void EnSkb_Update(Actor* actor, GameState* state);
void EnSkb_Draw(Actor* actor, GameState* state);

/*
ActorInit En_Skb_InitVars = {
    ACTOR_EN_SKB,
    ACTORCAT_ENEMY,
    FLAGS,
    OBJECT_SKB,
    sizeof(EnSkb),
    (ActorFunc)EnSkb_Init,
    (ActorFunc)EnSkb_Destroy,
    (ActorFunc)EnSkb_Update,
    (ActorFunc)EnSkb_Draw,
};
*/

#pragma GLOBAL_ASM("binary/EnSkb_Init.o")

#pragma GLOBAL_ASM("binary/EnSkb_Destroy.o")

#pragma GLOBAL_ASM("binary/EnSkb_Update.o")

#pragma GLOBAL_ASM("binary/EnSkb_Draw.o")
}
