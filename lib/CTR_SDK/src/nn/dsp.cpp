#include <nn/dsp.hpp>

#include <nn/err.hpp>
#include <nn/srv.hpp>
#include <nn/applet.hpp>

#include <std/cstring.hpp>

#include "non_matchings.hpp"

namespace nn {
namespace dsp {
namespace CTR {
namespace {
bool8 s_IsSleepAcceptedCallbackCalled;
bool8 s_IsComponentLoaded;
bool8 s_IsSleeping;
ubool8 s_IsWaitingForFinalize;

u16 s_RegisteredProgMask;
u16 s_RegisteredDataMask;
CTR::DSP* s_pDspSession;
u32 s_DspEventUsedFlag;
CTR::DSP s_DspSessionObject;
Handle s_DspSessionHandle(INVALID_HANDLE_VALUE);
void* s_RegisteredComponent;
u32 s_RegisteredComponentSize;

void (*s_SleepCallback[8])(void);
void (*s_WakeUpCallback[8])(void);
void (*s_FinalizeCallback[8])(void);

nn::applet::CTR::SysSleepAcceptedCallbackInfo s_SleepAcceptedCallbackInfo(0, 0, CTR::Sleep, 0, 0x8000);
}

const u32 zero = 0;
const char PORT_NAME_DSP[] = "dsp::DSP";

Result FlushDataCache(u32 address, u32 size) {
    Result result(0xC8A0A7F8);

    if (s_pDspSession != NULL) {
        const u32* handle = &PSEUDO_HANDLE_CURRENT_PROCESS;
        return s_pDspSession->FlushDataCache(*handle, address, size);
    }
    return Result(0xC8A0A7F8);
}

s8 IsComponentLoaded(void) {
    return s_IsComponentLoaded;
}

void Sleep(void) {
    bool8 isAwake = s_IsComponentLoaded & ~s_IsSleeping;
    if (isAwake) {
        for (int i = 0; i < 8; i++) {
            if (s_SleepCallback[i] != NULL) {
                s_SleepCallback[i]();
            }
        }
        if (s_IsComponentLoaded) {
            s_pDspSession->UnloadComponent();
            s_IsComponentLoaded = false;
        } else {
            s_IsComponentLoaded = false;
        }
        isAwake = returnTrueBool8(s_IsWaitingForFinalize);
        s_IsSleeping = isAwake;
    }
    s_IsSleepAcceptedCallbackCalled = isAwake;
}

void OrderToWaitForFinalize(void) {
    if (s_IsSleeping) {
        s_IsWaitingForFinalize = true;
        for (s32 i = 0; i < 8; i++) {
            if (s_FinalizeCallback[i] != NULL) {
                s_FinalizeCallback[i]();
            }
        }
        s_IsSleeping = false;
    }
}

void Awake(void) {
    if (s_IsSleepAcceptedCallbackCalled) {
        WakeUp();
    }
}

inline Result LoadComponent(const u8* component, u32 componentSize, u16 programMask, u16 dataMask, bool8* componentIsLoaded) {
    Result result;
    if ((s_pDspSession != NULL) && (!s_IsComponentLoaded)) {
        result = s_pDspSession->LoadComponent(component, componentSize, programMask, dataMask, componentIsLoaded);
    } else {
        result.SetCode(0xC8A0A7FCU);
    }
    return result;
}

void WakeUp(void) {
    Result result;
    u32 uVar1;

    s_IsSleepAcceptedCallbackCalled = false;
    if (s_IsSleeping) {
        result = LoadComponent((u8*)s_RegisteredComponent, s_RegisteredComponentSize, s_RegisteredProgMask, s_RegisteredDataMask, &s_IsComponentLoaded);
        uVar1 = result.GetCode() >> 0x1B;

        if (result.GetCode() & 0x80000000) {
            uVar1 -= 0x20;
        }
        if ((uVar1 != ~0x6) && (uVar1 != 0) && (uVar1 != 1)) {
            nn::err::CTR::ThrowFatalErr(result);
        }
        for (s32 i = 0; i < 8; i++) {
            if (s_WakeUpCallback[i] != NULL) {
                s_WakeUpCallback[i]();
            }
        }
        s_IsSleeping = false;
    }
}

// This seems to be an error check: for matching,
// it does need to be an inline'd helper like this.
// Does this belong in srv.hpp?
inline u32 GetTopBit(Result r) {
    return r.GetCode() >> 0x1F;
}

Result Initialize(void) {
    Result result;
    u32 nameLen;

    if (s_pDspSession != NULL) {
        result.SetCode(0);
    } else {
        result = nn::srv::Initialize();
        if (!GetTopBit(result)) {
            Handle* handle = &s_DspSessionHandle;

            nameLen = std::strlen(PORT_NAME_DSP);
            result = nn::srv::GetServiceHandle(handle, PORT_NAME_DSP, nameLen, 0);
            if (!GetTopBit(result)) {
                (s_pDspSession = &s_DspSessionObject);
                s_pDspSession->SetHandle(s_DspSessionHandle);
                for (u32 i = 0; i < 8; i++) {
                    s_FinalizeCallback[i] = NULL;
                    s_WakeUpCallback[i] = NULL;
                    s_SleepCallback[i] = NULL;
                }
                s_IsComponentLoaded = false;
                s_RegisteredComponent = NULL;
                s_RegisteredComponentSize = 0;
                s_RegisteredProgMask = 0;
                s_RegisteredDataMask = 0;
                s_IsSleeping = false;
                s_IsWaitingForFinalize = false;
                s_SleepAcceptedCallbackInfo.Register();
                result.SetCode(0);
            }
        }
    }
    return result;
}

Result SetSemaphore(u16 value) {
    Result result;
    result.SetCode(0xC8A0A7F8);

    if (s_pDspSession != NULL) {
        return s_pDspSession->SetSemaphore(value);
    } else {
        return result;
    }
}

Result RecvDataIsReady(u16 registerNum, bool* outIsReady) {
    Result result;
    result.SetCode(0xC8A0A7F8);

    if (s_pDspSession != NULL) {
        return s_pDspSession->RecvDataIsReady(registerNum, outIsReady);
    } else {
        return result;
    }
}

void UnloadComponent(void) {
    bool8 isAwake = s_IsComponentLoaded & ~s_IsSleeping;
    if (isAwake) {
        for (int i = 0; i < 8; i++) {
            if (s_SleepCallback[i] != NULL) {
                s_SleepCallback[i]();
            }
        }
        if (s_IsComponentLoaded) {
            s_pDspSession->UnloadComponent();
            s_IsComponentLoaded = false;
        } else {
            s_IsComponentLoaded = false;
        }
        isAwake = returnTrueBool8(s_IsWaitingForFinalize);
        s_IsSleeping = isAwake;
    }
}

Result WriteProcessPipe(s32 channel, const u8* buffer, u32 size) {
    Result result;
    result.SetCode(0xC8A0A7F8);

    if (s_pDspSession != NULL) {
        return s_pDspSession->WriteProcessPipe(channel, buffer, size);
    } else {
        return result;
    }
}


Result ReadPipeIfPossible(s32 channel, u8* buffer, u16 size, u16* outLengthRead) {
    Result result;
    result.SetCode(0xC8A0A7F8);

    if (s_pDspSession != NULL) {
        return s_pDspSession->ReadPipeIfPossible(channel, 0, buffer, size, outLengthRead);
    } else {
        return result;
    }
}

Result SetSemaphoreEventMask(u16 mask) {
    Result result;
    result.SetCode(0xC8A0A7F8);

    if (s_pDspSession != NULL) {
        return s_pDspSession->SetSemaphoreMask(mask);
    } else {
        return result;
    }
}

Result GetSemaphoreEventHandle(Handle* outHandle) {
    Result result;
    result.SetCode(0xC8A0A7F8);

    if (s_pDspSession != NULL) {
        return s_pDspSession->GetSemaphoreEventHandle(outHandle);
    } else {
        return result;
    }
}

Result RegisterInterruptEvents(Handle handle, s32 interrupt, s32 channel) {
    Result result;
    result.SetCode(0xC8A0A7F8);

    if (s_pDspSession != NULL) {
        if (handle.Value() != INVALID_HANDLE_VALUE) {
            if (!(s_DspEventUsedFlag & (1 << (interrupt + channel)))) {
                result = s_pDspSession->RegisterInterruptEvents(handle, interrupt, channel);
                s_DspEventUsedFlag |= (1 << (interrupt + channel));
            }
        } else {
            if (s_DspEventUsedFlag & (1 << (interrupt + channel))) {
                result = s_pDspSession->RegisterInterruptEvents(handle, interrupt, channel);
                s_DspEventUsedFlag &= ~(1 << (interrupt + channel));
            }
        }
    }
    return result;
}

bool RegisterSleepWakeUpCallback(void(*sleepCallback)(void), void(*wakeUpCallback)(void) , void(*finalizeCallback)(void)) {
    for (s32 i = 0; i < 8; i++) {
        if (s_SleepCallback[i] == NULL) {
            s_SleepCallback[i] = sleepCallback;
            s_WakeUpCallback[i] = wakeUpCallback;
            s_FinalizeCallback[i] = finalizeCallback;
            return true;
        }
    }
    return false;
}

Result ConvertProcessAddressFromDspDram(u32 address, u32* outAddress) {
    Result result;
    *outAddress = 0xFFFFFFFF;
    result.SetCode(0xC8A0A7F8);

    if (s_pDspSession != NULL) {
        s_pDspSession->ConvertProcessAddressFromDspDram(address, outAddress);
    }
    return result;
}

Result RecvData(u16 registerNumber, u16* outRegisterValue) {
    Result result;
    result.SetCode(0xC8A0A7F8);

    if (s_pDspSession != NULL) {
        return s_pDspSession->RecvData(registerNumber, outRegisterValue);
    } else {
        return result;
    }
}

Result GetHeadphoneStatus(bool* outStatus) {
    Result result;

    if (s_pDspSession != NULL) {
        return s_pDspSession->GetHeadphoneStatus(outStatus);
    } else {
        result.SetCode(0xC820A7F8);
        return result;
    }
}

} // namespace CTR
} // namespace dsp
} // namespace nn
