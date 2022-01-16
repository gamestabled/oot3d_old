extern "C" {
#include "z_en_okuta.hpp"

#define FLAGS 0x00000005

void EnOkuta_Init(Actor* actor, GameState* state);
void EnOkuta_Destroy(Actor* actor, GameState* state);
void EnOkuta_Update(Actor* actor, GameState* state);
void EnOkuta_Draw(Actor* actor, GameState* state);

GLOBAL_ASM("binary/z_En_Okuta.data.o")

ActorInit En_Okuta_InitVars = {
    ACTOR_EN_OKUTA,
    ACTORCAT_ENEMY,
    FLAGS,
    OBJECT_OKUTA,
    sizeof(EnOkuta),
    (ActorFunc)EnOkuta_Init,
    (ActorFunc)EnOkuta_Destroy,
    (ActorFunc)EnOkuta_Update,
    (ActorFunc)EnOkuta_Draw,
};

GLOBAL_ASM("binary/EnOkuta_Init.o")

GLOBAL_ASM("binary/EnOkuta_Destroy.o")

GLOBAL_ASM("binary/EnOkuta_Update.o")

GLOBAL_ASM("binary/EnOkuta_Draw.o")
}
