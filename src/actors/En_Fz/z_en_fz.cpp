extern "C" {
#include "z_en_fz.hpp"

#define FLAGS 0x00000415

void EnFz_Init(Actor* actor, GameState* state);
void EnFz_Destroy(Actor* actor, GameState* state);
void EnFz_Update(Actor* actor, GameState* state);
void EnFz_Draw(Actor* actor, GameState* state);

/*
ActorInit En_Fz_InitVars = {
    ACTOR_EN_FZ,
    ACTORCAT_ENEMY,
    FLAGS,
    OBJECT_FZ,
    sizeof(EnFz),
    (ActorFunc)EnFz_Init,
    (ActorFunc)EnFz_Destroy,
    (ActorFunc)EnFz_Update,
    (ActorFunc)EnFz_Draw,
};
*/

GLOBAL_ASM("binary/EnFz_Init.o")

GLOBAL_ASM("binary/EnFz_Destroy.o")

GLOBAL_ASM("binary/EnFz_Update.o")

GLOBAL_ASM("binary/EnFz_Draw.o")
}
