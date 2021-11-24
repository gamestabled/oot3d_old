extern "C" {
#include "z_en_horse.hpp"

#define FLAGS 0x80000010

void EnHorse_Init(Actor* actor, GameState* state);
void EnHorse_Destroy(Actor* actor, GameState* state);
void EnHorse_Update(Actor* actor, GameState* state);
void EnHorse_Draw(Actor* actor, GameState* state);

/*
ActorInit En_Horse_InitVars = {
    ACTOR_EN_HORSE,
    ACTORCAT_BG,
    FLAGS,
    OBJECT_HORSE,
    sizeof(EnHorse),
    (ActorFunc)EnHorse_Init,
    (ActorFunc)EnHorse_Destroy,
    (ActorFunc)EnHorse_Update,
    (ActorFunc)EnHorse_Draw,
};
*/

GLOBAL_ASM("binary/EnHorse_Init.o")

GLOBAL_ASM("binary/EnHorse_Destroy.o")

GLOBAL_ASM("binary/EnHorse_Update.o")

GLOBAL_ASM("binary/EnHorse_Draw.o")
}
