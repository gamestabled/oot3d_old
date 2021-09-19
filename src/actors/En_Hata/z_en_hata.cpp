extern "C" {
#include "z_en_hata.hpp"

#define FLAGS 0x00000000

void EnHata_Init(Actor* actor, GameState* state);
void EnHata_Destroy(Actor* actor, GameState* state);
void EnHata_Update(Actor* actor, GameState* state);
void EnHata_Draw(Actor* actor, GameState* state);

/*
ActorInit En_Hata_InitVars = {
    ACTOR_EN_HATA,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_HATA,
    sizeof(EnHata),
    (ActorFunc)EnHata_Init,
    (ActorFunc)EnHata_Destroy,
    (ActorFunc)EnHata_Update,
    (ActorFunc)EnHata_Draw,
};
*/

#pragma GLOBAL_ASM("binary/EnHata_Init.o")

#pragma GLOBAL_ASM("binary/EnHata_Destroy.o")

#pragma GLOBAL_ASM("binary/EnHata_Update.o")

#pragma GLOBAL_ASM("binary/EnHata_Draw.o")
}
