extern "C" {
#include "z_en_bom_bowl_man.hpp"

#define FLAGS 0x08000039

void EnBomBowlMan_Init(Actor* actor, GameState* state);
void EnBomBowlMan_Destroy(Actor* actor, GameState* state);
void EnBomBowlMan_Update(Actor* actor, GameState* state);
void EnBomBowlMan_Draw(Actor* actor, GameState* state);

GLOBAL_ASM("binary/z_En_Bom_Bowl_Man.data.o")

ActorInit En_Bom_Bowl_Man_InitVars = {
    ACTOR_EN_BOM_BOWL_MAN,
    ACTORCAT_NPC,
    FLAGS,
    OBJECT_BG,
    sizeof(EnBomBowlMan),
    (ActorFunc)EnBomBowlMan_Init,
    (ActorFunc)EnBomBowlMan_Destroy,
    (ActorFunc)EnBomBowlMan_Update,
    (ActorFunc)EnBomBowlMan_Draw,
};

GLOBAL_ASM("binary/EnBomBowlMan_Init.o")

GLOBAL_ASM("binary/EnBomBowlMan_Destroy.o")

GLOBAL_ASM("binary/EnBomBowlMan_Update.o")

GLOBAL_ASM("binary/EnBomBowlMan_Draw.o")
}
