extern "C" {
#include "z_bg_gnd_nisekabe.hpp"

#define FLAGS 0x80400010

void BgGndNisekabe_Init(Actor* actor, GameState* state);
void BgGndNisekabe_Destroy(Actor* actor, GameState* state);
void BgGndNisekabe_Update(Actor* actor, GameState* state);
void BgGndNisekabe_Draw(Actor* actor, GameState* state);

ActorInit Bg_Gnd_Nisekabe_InitVars = {
    ACTOR_BG_GND_NISEKABE,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_DEMO_KEKKAI,
    sizeof(BgGndNisekabe),
    (ActorFunc)BgGndNisekabe_Init,
    (ActorFunc)BgGndNisekabe_Destroy,
    (ActorFunc)BgGndNisekabe_Update,
    (ActorFunc)BgGndNisekabe_Draw,
};

void BgGndNisekabe_Init(Actor* actor, GameState* state) {
    BgGndNisekabe* self = (BgGndNisekabe*)actor;
    GlobalContext* globalCtx = (GlobalContext*)state;
  
    Actor_SetScale(&self->actor, 0.1);
    self->actor.uncullZoneForward = 3000.0;
    switch (self->actor.params & 0xFF) {
        case 0:
            FUN_00372f38(&self->actor, globalCtx, &self->skelAnimModel, 13, 0);
            break;
        case 1:
            FUN_00372f38(&self->actor, globalCtx, &self->skelAnimModel, 11, 0);
            break;
        case 2:
            FUN_00372f38(&self->actor, globalCtx, &self->skelAnimModel, 12, 0);
            break;
    }
}

void BgGndNisekabe_Destroy(Actor* actor, GameState* state) {
    BgGndNisekabe* self = (BgGndNisekabe*)actor;

    FUN_00350f34(&self->actor, &self->skelAnimModel, 0);
}

void BgGndNisekabe_Update(Actor* actor, GameState* state) {
    BgGndNisekabe* self = (BgGndNisekabe*)actor;
    GlobalContext* globalCtx = (GlobalContext*)state;

    if (globalCtx->actorCtx.unk_03 != 0) {
        self->actor.flags |= 0x80;
    } else {
        self->actor.flags &= ~0x80;
    }
}

void BgGndNisekabe_Draw(Actor* actor, GameState* state) {
    BgGndNisekabe* self = (BgGndNisekabe*)actor;
    nn_math_MTX34 modelMtx;

    MTX34CopyAsm(&modelMtx, &self->actor.modelMtx);
    if ((self->actor.flags & 0x80) == 0x80) {
        if (self->skelAnimModel != NULL) {
            self->skelAnimModel->unk_AC = 1;
            FUN_003721e0(self->skelAnimModel, &modelMtx);
            FUN_00372170(self->skelAnimModel, 0);
        }
    } else if (self->skelAnimModel != NULL) {
        self->skelAnimModel->unk_AC = 1;
        FUN_003721e0(self->skelAnimModel, &modelMtx);
        FUN_00372170(self->skelAnimModel, 0);
    }
}
}
