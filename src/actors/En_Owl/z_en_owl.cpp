extern "C" {
#include "z_en_owl.hpp"

#define FLAGS 0x00000019

void EnOwl_Init(Actor* actor, GameState* state);
void EnOwl_Destroy(Actor* actor, GameState* state);
void EnOwl_Update(Actor* actor, GameState* state);
void EnOwl_Draw(Actor* actor, GameState* state);

GLOBAL_ASM("binary/z_En_Owl.data.o")

ActorInit En_Owl_InitVars = {
    ACTOR_EN_OWL,
    ACTORCAT_NPC,
    FLAGS,
    OBJECT_OWL,
    sizeof(EnOwl),
    (ActorFunc)EnOwl_Init,
    (ActorFunc)EnOwl_Destroy,
    (ActorFunc)EnOwl_Update,
    (ActorFunc)EnOwl_Draw,
};

GLOBAL_ASM("binary/EnOwl_Init.o")

GLOBAL_ASM("binary/EnOwl_Destroy.o")

GLOBAL_ASM("binary/EnOwl_Update.o")

GLOBAL_ASM("binary/EnOwl_Draw.o")
}
