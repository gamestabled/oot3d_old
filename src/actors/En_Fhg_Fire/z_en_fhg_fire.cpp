extern "C" {
#include "z_en_fhg_fire.hpp"

#define FLAGS 0x00000030

void EnFhgFire_Init(Actor* actor, GameState* state);
void EnFhgFire_Destroy(Actor* actor, GameState* state);
void EnFhgFire_Update(Actor* actor, GameState* state);
void EnFhgFire_Draw(Actor* actor, GameState* state);

GLOBAL_ASM("binary/z_En_Fhg_Fire.data.o")

ActorInit En_Fhg_Fire_InitVars = {
    ACTOR_PLAYER,
    ACTORCAT_BOSS,
    FLAGS,
    OBJECT_FHG,
    sizeof(EnFhgFire),
    (ActorFunc)EnFhgFire_Init,
    (ActorFunc)EnFhgFire_Destroy,
    (ActorFunc)EnFhgFire_Update,
    (ActorFunc)EnFhgFire_Draw,
};

GLOBAL_ASM("binary/EnFhgFire_Init.o")

GLOBAL_ASM("binary/EnFhgFire_Destroy.o")

GLOBAL_ASM("binary/EnFhgFire_Update.o")

GLOBAL_ASM("binary/EnFhgFire_Draw.o")
}
