extern "C" {
#include "z_bg_treemouth.hpp"

#define FLAGS 0x80400030

void BgTreemouth_Init(Actor* actor, GameState* state);
void BgTreemouth_Destroy(Actor* actor, GameState* state);
void BgTreemouth_Update(Actor* actor, GameState* state);
void BgTreemouth_Draw(Actor* actor, GameState* state);

void FUN_0016e7f8(BgTreemouth* self, GlobalContext* globalCtx);
void FUN_001944c0(BgTreemouth* self, GlobalContext* globalCtx);
void FUN_001e466c(BgTreemouth* self, GlobalContext* globalCtx);
void FUN_002021a0(BgTreemouth* self, GlobalContext* globalCtx);
void FUN_00218d88(BgTreemouth* self, GlobalContext* globalCtx);
void FUN_003f48c4(BgTreemouth* self, GlobalContext* globalCtx);
void BgTreemouth_DoNothing(BgTreemouth* self, GlobalContext* globalCtx);

ActorInit Bg_Treemouth_InitVars = {
    ACTOR_BG_TREEMOUTH,
    ACTORCAT_BG,
    FLAGS,
    OBJECT_SPOT04_OBJECTS,
    sizeof(BgTreemouth),
    (ActorFunc)BgTreemouth_Init,
    (ActorFunc)BgTreemouth_Destroy,
    (ActorFunc)BgTreemouth_Update,
    (ActorFunc)BgTreemouth_Draw,
};

static InitChainEntry sInitChain[] = {
    ICHAIN_U8(targetMode, 5, ICHAIN_CONTINUE),
    ICHAIN_VEC3F(scale, 1, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneForward, 8000, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneScale, 300, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneDownward, 300, ICHAIN_STOP),
};

static void BgTreemouth_SetupAction(BgTreemouth* self, BgTreemouthActionFunc actionFunc) {
    self->actionFunc = actionFunc;
}

void BgTreemouth_Init(Actor* actor, GameState* state) {
    BgTreemouth* self = (BgTreemouth*)actor;
    GlobalContext* globalCtx = (GlobalContext*)state;
    CollisionHeader* colHeader = NULL;

    Actor_ProcessInitChain(actor, sInitChain);
    self->dyna.actor.unk_19A = 1;
    FUN_00372f38(&self->dyna.actor, globalCtx, &self->skelAnimModel, 2, 0);
    DynaPolyActor_Init(&self->dyna, DPM_UNK);
    ReadCollisionHeaderFromZsi(globalCtx->GetObjectStatus(self->dyna.actor.objBankIndex)->zarInfo.FUN_003532c0(0),
                              &colHeader);
    self->dyna.bgId = DynaPoly_SetBgActor(globalCtx, &globalCtx->colCtx.dyna, actor, colHeader);
    ActorShape_Init(&actor->shape, 0.0f, NULL, 0.0f);
    Actor_SetFocus(actor, 50.0f);

    if ((gSaveContext.sceneSetupIndex < 4) && !LINK_IS_ADULT) {
        BgTreemouth_SetupAction(self, FUN_003f48c4);
    } else if (LINK_IS_ADULT || (gSaveContext.sceneSetupIndex == 7)) {
        self->unk_1C0 = 0.0f;
        BgTreemouth_SetupAction(self, BgTreemouth_DoNothing);
    } else {
        self->unk_1C0 = 1.0f;
        BgTreemouth_SetupAction(self, FUN_001e466c);
    }

    actor->textId = 0x905;
}

void BgTreemouth_Destroy(Actor* actor, GameState* state) {
    BgTreemouth* self = (BgTreemouth*)actor;
    GlobalContext* globalCtx = (GlobalContext*)state;

    FUN_00350f34(&self->dyna.actor, &self->skelAnimModel, 0);
    DynaPoly_DeleteBgActor(globalCtx, &globalCtx->colCtx.dyna, self->dyna.bgId);
}

void FUN_0016e5a4(BgTreemouth* self, GlobalContext* globalCtx) {
    CsCmdActorAction* npcAction;

    if ((globalCtx->GetCutsceneState() != CS_STATE_IDLE)) {
        npcAction = globalCtx->csCtx.npcActions[0];
        if (npcAction != NULL) {
            if (npcAction->action == 2) {
                BgTreemouth_SetupAction(self, FUN_002021a0);
            } else if (npcAction->action == 3) {
                Audio_PlaySoundGeneral(0x10001BD, NULL, 4, &FLOAT_0054ac20, &FLOAT_0054ac20, &DAT_0054ac24);
                BgTreemouth_SetupAction(self, FUN_001e466c);
            }
        }
    }
}

void FUN_001e466c(BgTreemouth* self, GlobalContext* globalCtx) {
    Vec3f sp34;

    if (self->unk_1C0 < 1.0f) {
        self->unk_1C0 += ADJUST_F32_FOR_FRAMERATE(0.01f);
    } else {
        self->unk_1C0 = 1.0f;
    }

    if ((gSaveContext.sceneSetupIndex == 6) && !(ADJUST_FRAMECOUNT(700) >= globalCtx->csCtx.frames) &&
        (globalCtx->state.frames % 8 == 0)) {
        sp34.x = (Rand_ZeroOne() * 1158.0f) + 3407.0f;
        sp34.y = 970.0f;
        sp34.z = (Rand_ZeroOne() * 2026.0f) + -2163.0f;
        EffectSsHahen_SpawnBurst(globalCtx, &sp34, 0.8f, 0, 50, 30, 1, -1, 10, NULL);
    }
}

void FUN_002021a0(BgTreemouth* self, GlobalContext* globalCtx) {
    self->unk_1C0 += ADJUST_F32_FOR_FRAMERATE(0.05f);
    if (self->unk_1C0 >= 0.8f) {
        BgTreemouth_SetupAction(self, FUN_00218d88);
    }
}

void FUN_00218d88(BgTreemouth* self, GlobalContext* globalCtx) {
    self->unk_1C0 -= ADJUST_F32_FOR_FRAMERATE(0.03f);
    if (self->unk_1C0 <= 0.0f) {
        BgTreemouth_SetupAction(self, FUN_0016e5a4);
    }
}

void FUN_003f48c4(BgTreemouth* self, GlobalContext* globalCtx) {
    if ((!(Flags_GetEventChkInf(5))) || LINK_IS_ADULT) {
        if (!LINK_IS_ADULT) {
            if (Flags_GetEventChkInf(0xC)) {
                if (Actor_IsFacingAndNearPlayer(&self->dyna.actor, 1658.0f, 0x7530)) {
                    self->dyna.actor.flags |= 1;
                    if (self->dyna.actor.isTargeted) {
                        self->dyna.actor.flags &= ~1;
                        globalCtx->FUN_0037573c(
                            globalCtx->GetObjectStatus(self->dyna.actor.objBankIndex)->zarInfo.GetQDBByIndex(1));
                        gSaveContext.cutsceneTrigger = 1;
                        BgTreemouth_SetupAction(self, FUN_0016e7f8);
                    }
                }
            } else if (Actor_IsFacingAndNearPlayer(&self->dyna.actor, 1658.0f, 0x4E20)) {
                Flags_SetEventChkInf(0xC);
                globalCtx->FUN_0037573c(
                    globalCtx->GetObjectStatus(self->dyna.actor.objBankIndex)->zarInfo.GetQDBByIndex(0));
                gSaveContext.cutsceneTrigger = 1;
                BgTreemouth_SetupAction(self, FUN_0016e7f8);
            }
        }
    } else {
        self->unk_1C0 = 1.0f;
    }
}

void FUN_0016e7f8(BgTreemouth* self, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);

    if (globalCtx->GetCutsceneState() == CS_STATE_UNSKIPPABLE_INIT) {
        if (Actor_IsFacingAndNearPlayer(&self->dyna.actor, 350.0f, 0x7530)) {
            player->actor.world.pos.x = 3827.0f;
            player->actor.world.pos.y = -161.0f;
            player->actor.world.pos.z = -1142.0f;
        }

        globalCtx->csCtx.frames = 0;
        globalCtx->csCtx.unk_28 = 0xFFFF;
        globalCtx->csCtx.unk_2A = 0xFFFF;
        globalCtx->csCtx.unk_2C = 0xFFFF;
        globalCtx->csCtx.unk_2E = 0xFFFF;
        globalCtx->csCtx.unk_34 = 0;
        globalCtx->csCtx.unk_35 = 0;

        globalCtx->SetCutsceneState(CS_STATE_SKIPPABLE_EXEC);

        if (FUN_00369f3c(globalCtx) == 0) {
            globalCtx->FUN_0037573c(
                globalCtx->GetObjectStatus(self->dyna.actor.objBankIndex)->zarInfo.GetQDBByIndex(2));
            Flags_SetEventChkInf(5);
            BgTreemouth_SetupAction(self, FUN_001944c0);
        } else {
            globalCtx->FUN_0037573c(
                globalCtx->GetObjectStatus(self->dyna.actor.objBankIndex)->zarInfo.GetQDBByIndex(3));
            globalCtx->csCtx.frames = 0;
            BgTreemouth_SetupAction(self, FUN_003f48c4);
        }
    }
}

void FUN_001944c0(BgTreemouth* self, GlobalContext* globalCtx) {
    CsCmdActorAction* npcAction;

    if (globalCtx->GetCutsceneState() != CS_STATE_IDLE) {
        npcAction = globalCtx->csCtx.npcActions[0];
        if (npcAction != NULL) {
            if (npcAction->action == 2) {
                BgTreemouth_SetupAction(self, FUN_002021a0);
            } else if (npcAction->action == 3) {
                Audio_PlaySoundGeneral(0x10001BD, NULL, 4, &FLOAT_0054ac20, &FLOAT_0054ac20, &DAT_0054ac24);
                BgTreemouth_SetupAction(self, FUN_001e466c);
            }
        }
    }
}

void BgTreemouth_DoNothing(BgTreemouth* self, GlobalContext* globalCtx) {
}

void BgTreemouth_Update(Actor* actor, GameState* state) {
    static const Vector3f unused1(-2746.0f, 545.0f, 4694.0f);
    static const Vector3f unused2(-2654.0f, 146.0f, 4534.0f);

    BgTreemouth* self = (BgTreemouth*)actor;
    GlobalContext* globalCtx = (GlobalContext*)state;

    self->actionFunc(self, globalCtx);
    self->dyna.actor.world.pos.x = (self->unk_1C0 * -160.0f) + 4029.0f;
    self->dyna.actor.world.pos.y = (self->unk_1C0 * -399.0f) + 136.0f;
    self->dyna.actor.world.pos.z = (self->unk_1C0 * 92.0f) + -1255.0f;
}

void BgTreemouth_Draw(Actor* actor, GameState* state) {
    GlobalContext* globalCtx = (GlobalContext*)state;
    u16 alpha = 0;

    if (gSaveContext.sceneSetupIndex == 6) {
        alpha = globalCtx->roomCtx.unk_7C0;
    } else if ((gSaveContext.sceneSetupIndex < 4) || LINK_IS_ADULT) {
        if (gSaveContext.eventChkInf[0] & 0x80) {
            alpha = 1660;
        }
    } else {
        alpha = 0;
    }

    BgTreemouth* self = (BgTreemouth*)actor;

    FUN_003695cc(self->skelAnimModel, 0, 4, 2, 0.5019608f, 0.5019608f, 0.5019608f, 1.0f - alpha * 0.000602409651037f);
    self->skelAnimModel->FUN_003721e0(&self->dyna.actor.modelMtx);
    self->skelAnimModel->SetUnkAC(1);
    self->skelAnimModel->FUN_00372170(0);
}
}
