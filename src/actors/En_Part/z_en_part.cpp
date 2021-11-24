extern "C" {
#include "z_en_part.hpp"

#define FLAGS 0x00000010

void EnPart_Init(Actor* actor, GameState* state);
void EnPart_Destroy(Actor* actor, GameState* state);
void EnPart_Update(Actor* actor, GameState* state);
void EnPart_Draw(Actor* actor, GameState* state);

/*
ActorInit En_Part_InitVars = {
    ACTOR_EN_PART,
    ACTORCAT_ITEMACTION,
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(EnPart),
    (ActorFunc)EnPart_Init,
    (ActorFunc)EnPart_Destroy,
    (ActorFunc)EnPart_Update,
    (ActorFunc)EnPart_Draw,
};
*/

GLOBAL_ASM("binary/EnPart_Init.o")

GLOBAL_ASM("binary/EnPart_Destroy.o")

GLOBAL_ASM("binary/EnPart_Update.o")

GLOBAL_ASM("binary/EnPart_Draw.o")
}
