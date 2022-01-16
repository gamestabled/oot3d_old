extern "C" {
#include "z_en_ru2.hpp"

#define FLAGS 0x00000010

void EnRu2_Init(Actor* actor, GameState* state);
void EnRu2_Destroy(Actor* actor, GameState* state);
void EnRu2_Update(Actor* actor, GameState* state);
void EnRu2_Draw(Actor* actor, GameState* state);

GLOBAL_ASM("binary/z_En_Ru2.data.o")

ActorInit En_Ru2_InitVars = {
    ACTOR_EN_RU2,
    ACTORCAT_NPC,
    FLAGS,
    OBJECT_RU2,
    sizeof(EnRu2),
    (ActorFunc)EnRu2_Init,
    (ActorFunc)EnRu2_Destroy,
    (ActorFunc)EnRu2_Update,
    (ActorFunc)EnRu2_Draw,
};

GLOBAL_ASM("binary/EnRu2_Init.o")

GLOBAL_ASM("binary/EnRu2_Destroy.o")

GLOBAL_ASM("binary/EnRu2_Update.o")

GLOBAL_ASM("binary/EnRu2_Draw.o")
}
