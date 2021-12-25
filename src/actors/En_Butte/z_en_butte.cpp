extern "C" {
#include "z_en_butte.hpp"

#define FLAGS 0x00000000

void EnButte_Init(Actor* actor, GameState* state);
void EnButte_Destroy(Actor* actor, GameState* state);
void EnButte_Update(Actor* actor, GameState* state);
void EnButte_Draw(Actor* actor, GameState* state);

GLOBAL_ASM("binary/z_En_Butte.data.o")

/*
ActorInit En_Butte_InitVars = {
    ACTOR_EN_BUTTE,
    ACTORCAT_ITEMACTION,
    FLAGS,
    OBJECT_GAMEPLAY_FIELD_KEEP,
    sizeof(EnButte),
    (ActorFunc)EnButte_Init,
    (ActorFunc)EnButte_Destroy,
    (ActorFunc)EnButte_Update,
    (ActorFunc)EnButte_Draw,
};
*/

GLOBAL_ASM("binary/EnButte_Init.o")

GLOBAL_ASM("binary/EnButte_Destroy.o")

GLOBAL_ASM("binary/EnButte_Update.o")

GLOBAL_ASM("binary/EnButte_Draw.o")
}
