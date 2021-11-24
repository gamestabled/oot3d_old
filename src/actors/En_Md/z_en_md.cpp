extern "C" {
#include "z_en_md.hpp"

#define FLAGS 0x02000019

void EnMd_Init(Actor* actor, GameState* state);
void EnMd_Destroy(Actor* actor, GameState* state);
void EnMd_Update(Actor* actor, GameState* state);
void EnMd_Draw(Actor* actor, GameState* state);

/*
ActorInit En_Md_InitVars = {
    ACTOR_EN_MD,
    ACTORCAT_NPC,
    FLAGS,
    OBJECT_MD,
    sizeof(EnMd),
    (ActorFunc)EnMd_Init,
    (ActorFunc)EnMd_Destroy,
    (ActorFunc)EnMd_Update,
    (ActorFunc)EnMd_Draw,
};
*/

GLOBAL_ASM("binary/EnMd_Init.o")

GLOBAL_ASM("binary/EnMd_Destroy.o")

GLOBAL_ASM("binary/EnMd_Update.o")

GLOBAL_ASM("binary/EnMd_Draw.o")
}
