extern "C" {
#include "z3Dactor.hpp"
#include "z3D.hpp"

typedef void (*EnOE2ActionFunc)(struct EnOE2*, GlobalContext*);

typedef struct EnOE2 {
    /* 0x000 */ Actor actor;
    /* 0x1A4 */ char unk_1A4[0x48];
    /* 0x1EC */ EnOE2ActionFunc actionFunc;
} EnOE2;

void EnOE2_Init(Actor* actor, GameState* state);
void EnOE2_Destroy(Actor* actor, GameState* state);
void EnOE2_Update(Actor* actor, GameState* state);
void EnOE2_Draw(Actor* actor, GameState* state);

void EnOE2_DoNothing(EnOE2* self, GlobalContext* globalCtx);

inline void EnOE2_SetupAction(EnOE2* self, EnOE2ActionFunc actionFunc) {
    self->actionFunc = actionFunc;
}

void EnOE2_Init(Actor* actor, GameState* state) {
    EnOE2* self = (EnOE2*)actor;

    EnOE2_SetupAction(self, EnOE2_DoNothing);
}

void EnOE2_Destroy(Actor* actor, GameState* state) {
}

void EnOE2_DoNothing(EnOE2* self, GlobalContext* globalCtx) {
}

void EnOE2_Update(Actor* actor, GameState* state) {
}

void EnOE2_Draw(Actor* actor, GameState* state) {
}
}
