extern "C" {
#include "z_bg_toki_hikari.hpp"

#define FLAGS 0x80400020

void BgTokiHikari_Init(Actor* actor, GameState* state);
void BgTokiHikari_Destroy(Actor* actor, GameState* state);
void BgTokiHikari_Update(Actor* actor, GameState* state);
void BgTokiHikari_Draw(Actor* actor, GameState* state);

GLOBAL_ASM("binary/z_Bg_Toki_Hikari.data.o")

ActorInit Bg_Toki_Hikari_InitVars = {
    ACTOR_BG_TOKI_HIKARI,
    ACTORCAT_BG,
    FLAGS,
    OBJECT_TOKI_OBJECTS,
    sizeof(BgTokiHikari),
    (ActorFunc)BgTokiHikari_Init,
    (ActorFunc)BgTokiHikari_Destroy,
    (ActorFunc)BgTokiHikari_Update,
    (ActorFunc)BgTokiHikari_Draw,
};

GLOBAL_ASM("binary/BgTokiHikari_Init.o")

GLOBAL_ASM("binary/BgTokiHikari_Destroy.o")

GLOBAL_ASM("binary/BgTokiHikari_Update.o")

GLOBAL_ASM("binary/BgTokiHikari_Draw.o")
}
