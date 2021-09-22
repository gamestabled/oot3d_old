#include "global.hpp"

void GlobalContext::FUN_0037573c(void* csSegment) {
    csCtx.segment = csSegment;
    csCtx.unk_14 = 0;
}

u8 GlobalContext::GetCutsceneState() {
    CutsceneContext* tmpCsCtx = &this->csCtx;

    return tmpCsCtx->state;
}

void GlobalContext::SetCutsceneState(u8 csState) {
    CutsceneContext* tmpCsCtx = &this->csCtx;

    tmpCsCtx->state = csState;
}
