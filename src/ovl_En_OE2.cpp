#include "actor.hpp"

typedef void (*EnOE2ActionFunc)(struct EnOE2*, GlobalContext*);

typedef struct EnOE2 {
    /* 0x000 */ Actor actor;
    /* 0x1A4 */ char unk_1A4[0x48];
    /* 0x1EC */ EnOE2ActionFunc actionFunc;
} EnOE2;

#define SELF ((EnOE2*)super)

void EnOE2_Init(Actor* super, GlobalContext* globalCtx);
void EnOE2_Destroy(Actor* super, GlobalContext* globalCtx);
void EnOE2_Update(Actor* super, GlobalContext* globalCtx);
void EnOE2_Draw(Actor* super, GlobalContext* globalCtx);

void EnOE2_DoNothing(EnOE2* self, GlobalContext* globalCtx);

void EnOE2_SetupAction(EnOE2* self, EnOE2ActionFunc actionFunc) {
    self->actionFunc = actionFunc;
}

/* This function is not included in the rom, but it demonstrates a problem:
 * It needs to be linked with EnOe2_DoNothing. With the current method of
 * converting from ARM .o files to GCC .o files, this is simply impossible
 * Obviously this is a huge problem and it is a fundamental issue with how
 * this repository is set up. We may need to reconsider how the build process works.
 */
void EnOE2_Init(Actor* super, GlobalContext* globalCtx) {
    EnOE2* self = SELF;

    EnOE2_SetupAction(self, EnOE2_DoNothing);
}

__attribute__((section("EnOE2_Destroy")))
void EnOE2_Destroy(Actor* super, GlobalContext* globalCtx) {
}

__attribute__((section("EnOE2_DoNothing")))
void EnOE2_DoNothing(EnOE2* self, GlobalContext* globalCtx) {
}

__attribute__((section("EnOE2_Update")))
void EnOE2_Update(Actor* super, GlobalContext* globalCtx) {
}

__attribute__((section("EnOE2_Draw")))
void EnOE2_Draw(Actor* super, GlobalContext* globalCtx) {
}
