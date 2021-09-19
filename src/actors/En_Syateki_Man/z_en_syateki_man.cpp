extern "C" {
#include "z_en_syateki_man.hpp"

#define FLAGS 0x08000019

void EnSyatekiMan_Init(Actor* actor, GameState* state);
void EnSyatekiMan_Destroy(Actor* actor, GameState* state);
void EnSyatekiMan_Update(Actor* actor, GameState* state);
void EnSyatekiMan_Draw(Actor* actor, GameState* state);

/*
ActorInit En_Syateki_Man_InitVars = {
    ACTOR_EN_SYATEKI_MAN,
    ACTORCAT_NPC,
    FLAGS,
    OBJECT_OSSAN,
    sizeof(EnSyatekiMan),
    (ActorFunc)EnSyatekiMan_Init,
    (ActorFunc)EnSyatekiMan_Destroy,
    (ActorFunc)EnSyatekiMan_Update,
    (ActorFunc)EnSyatekiMan_Draw,
};
*/

#pragma GLOBAL_ASM("binary/EnSyatekiMan_Init.o")

#pragma GLOBAL_ASM("binary/EnSyatekiMan_Destroy.o")

#pragma GLOBAL_ASM("binary/EnSyatekiMan_Update.o")

#pragma GLOBAL_ASM("binary/EnSyatekiMan_Draw.o")
}
