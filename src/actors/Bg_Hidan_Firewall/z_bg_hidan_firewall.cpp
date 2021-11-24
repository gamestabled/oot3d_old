extern "C" {
#include "z_bg_hidan_firewall.hpp"

#define FLAGS 0x80400000

void BgHidanFirewall_Init(Actor* actor, GameState* state);
void BgHidanFirewall_Destroy(Actor* actor, GameState* state);
void BgHidanFirewall_Update(Actor* actor, GameState* state);

/*
ActorInit Bg_Hidan_Firewall_InitVars = {
    ACTOR_BG_HIDAN_FIREWALL,
    ACTORCAT_BG,
    FLAGS,
    OBJECT_HIDAN_OBJECTS,
    sizeof(BgHidanFirewall),
    (ActorFunc)BgHidanFirewall_Init,
    (ActorFunc)BgHidanFirewall_Destroy,
    (ActorFunc)BgHidanFirewall_Update,
    (ActorFunc)NULL,
};
*/

GLOBAL_ASM("binary/BgHidanFirewall_Init.o")

GLOBAL_ASM("binary/BgHidanFirewall_Destroy.o")

GLOBAL_ASM("binary/BgHidanFirewall_Update.o")
}
