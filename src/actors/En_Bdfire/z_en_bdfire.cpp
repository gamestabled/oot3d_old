extern "C" {
#include "z_en_bdfire.hpp"

#define FLAGS 0x00000030

void EnBdfire_Init(Actor* actor, GameState* state);
void EnBdfire_Destroy(Actor* actor, GameState* state);
void EnBdfire_Update(Actor* actor, GameState* state);
void EnBdfire_Draw(Actor* actor, GameState* state);

GLOBAL_ASM("binary/z_En_Bdfire.data.o")

ActorInit En_Bdfire_InitVars = {
    ACTOR_PLAYER,
    ACTORCAT_ENEMY,
    FLAGS,
    OBJECT_KINGDODONGO,
    sizeof(EnBdfire),
    (ActorFunc)EnBdfire_Init,
    (ActorFunc)EnBdfire_Destroy,
    (ActorFunc)EnBdfire_Update,
    (ActorFunc)EnBdfire_Draw,
};

GLOBAL_ASM("binary/EnBdfire_Init.o")

GLOBAL_ASM("binary/EnBdfire_Destroy.o")

GLOBAL_ASM("binary/EnBdfire_Update.o")

GLOBAL_ASM("binary/EnBdfire_Draw.o")
}
