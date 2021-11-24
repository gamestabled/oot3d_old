extern "C" {
#include "z_en_box.hpp"

#define FLAGS 0x00000000

void EnBox_Init(Actor* actor, GameState* state);
void EnBox_Destroy(Actor* actor, GameState* state);
void EnBox_Update(Actor* actor, GameState* state);
void EnBox_Draw(Actor* actor, GameState* state);

/*
ActorInit En_Box_InitVars = {
    ACTOR_EN_BOX,
    ACTORCAT_CHEST,
    FLAGS,
    OBJECT_BOX,
    sizeof(EnBox),
    (ActorFunc)EnBox_Init,
    (ActorFunc)EnBox_Destroy,
    (ActorFunc)EnBox_Update,
    (ActorFunc)EnBox_Draw,
};
*/

GLOBAL_ASM("binary/EnBox_Init.o")

GLOBAL_ASM("binary/EnBox_Destroy.o")

GLOBAL_ASM("binary/EnBox_Update.o")

GLOBAL_ASM("binary/EnBox_Draw.o")
}
