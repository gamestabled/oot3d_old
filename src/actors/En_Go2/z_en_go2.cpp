extern "C" {
#include "z_en_go2.hpp"

#define FLAGS 0x00000039

void EnGo2_Init(Actor* actor, GameState* state);
void EnGo2_Destroy(Actor* actor, GameState* state);
void EnGo2_Update(Actor* actor, GameState* state);
void EnGo2_Draw(Actor* actor, GameState* state);

GLOBAL_ASM("binary/z_En_Go2.data.o")

ActorInit En_Go2_InitVars = {
    ACTOR_EN_GO2,
    ACTORCAT_NPC,
    FLAGS,
    OBJECT_OF1D_MAP,
    sizeof(EnGo2),
    (ActorFunc)EnGo2_Init,
    (ActorFunc)EnGo2_Destroy,
    (ActorFunc)EnGo2_Update,
    (ActorFunc)EnGo2_Draw,
};

GLOBAL_ASM("binary/EnGo2_Init.o")

GLOBAL_ASM("binary/EnGo2_Destroy.o")

GLOBAL_ASM("binary/EnGo2_Update.o")

GLOBAL_ASM("binary/EnGo2_Draw.o")
}
