extern "C" {
#include "z_en_lightbox.hpp"

#define FLAGS 0x80000010

void EnLightbox_Init(Actor* actor, GameState* state);
void EnLightbox_Destroy(Actor* actor, GameState* state);
void EnLightbox_Update(Actor* actor, GameState* state);
void EnLightbox_Draw(Actor* actor, GameState* state);

GLOBAL_ASM("binary/z_En_Lightbox.data.o")

/*
ActorInit En_Lightbox_InitVars = {
    ACTOR_EN_LIGHTBOX,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_LIGHTBOX,
    sizeof(EnLightbox),
    (ActorFunc)EnLightbox_Init,
    (ActorFunc)EnLightbox_Destroy,
    (ActorFunc)EnLightbox_Update,
    (ActorFunc)EnLightbox_Draw,
};
*/

GLOBAL_ASM("binary/EnLightbox_Init.o")

GLOBAL_ASM("binary/EnLightbox_Destroy.o")

GLOBAL_ASM("binary/EnLightbox_Update.o")

GLOBAL_ASM("binary/EnLightbox_Draw.o")
}
