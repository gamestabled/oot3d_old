extern "C" {
#include "z_bg_ganon_otyuka.hpp"

#define FLAGS 0x80400030

void BgGanonOtyuka_Init(Actor* actor, GameState* state);
void BgGanonOtyuka_Destroy(Actor* actor, GameState* state);
void BgGanonOtyuka_Update(Actor* actor, GameState* state);
void BgGanonOtyuka_Draw(Actor* actor, GameState* state);

GLOBAL_ASM("binary/z_Bg_Ganon_Otyuka.data.o")

/*
ActorInit Bg_Ganon_Otyuka_InitVars = {
    ACTOR_BG_GANON_OTYUKA,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_GANON,
    sizeof(BgGanonOtyuka),
    (ActorFunc)BgGanonOtyuka_Init,
    (ActorFunc)BgGanonOtyuka_Destroy,
    (ActorFunc)BgGanonOtyuka_Update,
    (ActorFunc)BgGanonOtyuka_Draw,
};
*/

GLOBAL_ASM("binary/BgGanonOtyuka_Init.o")

GLOBAL_ASM("binary/BgGanonOtyuka_Destroy.o")

GLOBAL_ASM("binary/BgGanonOtyuka_Update.o")

GLOBAL_ASM("binary/BgGanonOtyuka_Draw.o")
}
