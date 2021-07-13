#ifndef _Z_BG_HIDAN_FIREWALL_H_
#define _Z_BG_HIDAN_FIREWALL_H_

#include "global.hpp"

struct BgHidanFirewall;

typedef struct BgHidanFirewall {
    /* 0x0000 */ Actor actor;
    /* 0x01A4 */ char unk_1A4[0x64];
} BgHidanFirewall; // size = 0x208

extern ActorInit Bg_Hidan_Firewall_InitVars;

#endif
