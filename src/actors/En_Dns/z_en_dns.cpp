extern "C" {
#include "z_en_dns.hpp"

#define FLAGS 0x00000009

void EnDns_Init(Actor* actor, GameState* state);
void EnDns_Destroy(Actor* actor, GameState* state);
void EnDns_Update(Actor* actor, GameState* state);
void EnDns_Draw(Actor* actor, GameState* state);

GLOBAL_ASM("binary/z_En_Dns.data.o")

/*
ActorInit En_Dns_InitVars = {
    ACTOR_EN_DNS,
    ACTORCAT_BG,
    FLAGS,
    OBJECT_SHOPNUTS,
    sizeof(EnDns),
    (ActorFunc)EnDns_Init,
    (ActorFunc)EnDns_Destroy,
    (ActorFunc)EnDns_Update,
    (ActorFunc)EnDns_Draw,
};
*/

GLOBAL_ASM("binary/EnDns_Init.o")

GLOBAL_ASM("binary/EnDns_Destroy.o")

GLOBAL_ASM("binary/EnDns_Update.o")

GLOBAL_ASM("binary/EnDns_Draw.o")
}
