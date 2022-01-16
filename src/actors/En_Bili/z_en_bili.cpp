extern "C" {
#include "z_en_bili.hpp"

#define FLAGS 0x00005005

void EnBili_Init(Actor* actor, GameState* state);
void EnBili_Destroy(Actor* actor, GameState* state);
void EnBili_Update(Actor* actor, GameState* state);
void EnBili_Draw(Actor* actor, GameState* state);

GLOBAL_ASM("binary/z_En_Bili.data.o")

ActorInit En_Bili_InitVars = {
    ACTOR_EN_BILI,
    ACTORCAT_ENEMY,
    FLAGS,
    OBJECT_BL,
    sizeof(EnBili),
    (ActorFunc)EnBili_Init,
    (ActorFunc)EnBili_Destroy,
    (ActorFunc)EnBili_Update,
    (ActorFunc)EnBili_Draw,
};

GLOBAL_ASM("binary/EnBili_Init.o")

GLOBAL_ASM("binary/EnBili_Destroy.o")

GLOBAL_ASM("binary/EnBili_Update.o")

GLOBAL_ASM("binary/EnBili_Draw.o")
}
