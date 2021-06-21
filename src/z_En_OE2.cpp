extern "C" {
#include "z3Dactor.hpp"

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

inline void EnOE2_SetupAction(EnOE2* self, EnOE2ActionFunc actionFunc) {
    self->actionFunc = actionFunc;
}

void EnOE2_Init(Actor* super, GlobalContext* globalCtx) {
    EnOE2* self = SELF;

    EnOE2_SetupAction(self, EnOE2_DoNothing);
}

void EnOE2_Destroy(Actor* super, GlobalContext* globalCtx) {
}

void EnOE2_DoNothing(EnOE2* self, GlobalContext* globalCtx) {
}

void EnOE2_Update(Actor* super, GlobalContext* globalCtx) {
}

void EnOE2_Draw(Actor* super, GlobalContext* globalCtx) {
}
}
