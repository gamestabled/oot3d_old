extern "C" {
#include "z_en_heishi2.hpp"

#define FLAGS 0x00000009

void EnHeishi2_Init(Actor* actor, GameState* state);
void EnHeishi2_Destroy(Actor* actor, GameState* state);
void EnHeishi2_Update(Actor* actor, GameState* state);
void EnHeishi2_Draw(Actor* actor, GameState* state);

GLOBAL_ASM("binary/z_En_Heishi2.data.o")

ActorInit En_Heishi2_InitVars = {
    ACTOR_EN_HEISHI2,
    ACTORCAT_NPC,
    FLAGS,
    OBJECT_SD,
    sizeof(EnHeishi2),
    (ActorFunc)EnHeishi2_Init,
    (ActorFunc)EnHeishi2_Destroy,
    (ActorFunc)EnHeishi2_Update,
    (ActorFunc)EnHeishi2_Draw,
};

GLOBAL_ASM("binary/EnHeishi2_Init.o")

GLOBAL_ASM("binary/EnHeishi2_Destroy.o")

GLOBAL_ASM("binary/EnHeishi2_Update.o")

GLOBAL_ASM("binary/EnHeishi2_Draw.o")
}
