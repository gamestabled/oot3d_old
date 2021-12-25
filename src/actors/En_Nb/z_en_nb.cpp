extern "C" {
#include "z_en_nb.hpp"

#define FLAGS 0x00000010

void EnNb_Init(Actor* actor, GameState* state);
void EnNb_Destroy(Actor* actor, GameState* state);
void EnNb_Update(Actor* actor, GameState* state);
void EnNb_Draw(Actor* actor, GameState* state);

GLOBAL_ASM("binary/z_En_Nb.data.o")

/*
ActorInit En_Nb_InitVars = {
    ACTOR_EN_NB,
    ACTORCAT_NPC,
    FLAGS,
    OBJECT_NB,
    sizeof(EnNb),
    (ActorFunc)EnNb_Init,
    (ActorFunc)EnNb_Destroy,
    (ActorFunc)EnNb_Update,
    (ActorFunc)EnNb_Draw,
};
*/

GLOBAL_ASM("binary/EnNb_Init.o")

GLOBAL_ASM("binary/EnNb_Destroy.o")

GLOBAL_ASM("binary/EnNb_Update.o")

GLOBAL_ASM("binary/EnNb_Draw.o")
}
