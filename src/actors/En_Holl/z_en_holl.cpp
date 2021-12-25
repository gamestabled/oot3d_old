extern "C" {
#include "z_en_holl.hpp"

#define FLAGS 0x00000010

void EnHoll_Init(Actor* actor, GameState* state);
void EnHoll_Destroy(Actor* actor, GameState* state);
void EnHoll_Update(Actor* actor, GameState* state);
void EnHoll_Draw(Actor* actor, GameState* state);

GLOBAL_ASM("binary/z_En_Holl.data.o")

/*
ActorInit En_Holl_InitVars = {
    ACTOR_EN_HOLL,
    ACTORCAT_DOOR,
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(EnHoll),
    (ActorFunc)EnHoll_Init,
    (ActorFunc)EnHoll_Destroy,
    (ActorFunc)EnHoll_Update,
    (ActorFunc)EnHoll_Draw,
};
*/

GLOBAL_ASM("binary/EnHoll_Init.o")

GLOBAL_ASM("binary/EnHoll_Destroy.o")

GLOBAL_ASM("binary/EnHoll_Update.o")

GLOBAL_ASM("binary/EnHoll_Draw.o")
}
