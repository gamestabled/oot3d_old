#include <nn/dsp.hpp>

#include <nn/err.hpp>
#include <nn/srv.hpp>
#include <nn/applet.hpp>

#include <std/cstring.hpp>

#include "non_matchings.hpp"

namespace nn {
namespace dsp {

bool8 wereSleepCallbacksCalled;
bool8 isComponentLoaded;
bool8 isAsleep;
ubool8 isFinalized;

u16 registeredProgramMask;
u16 registeredDataMask;
CTR::DSP* session;
u32 eventUsedFlags;
CTR::DSP sessionObject;
Handle sessionHandle(0);
void* registeredComponent;
u32 registeredComponentSize;

void (*sleepCallbacks[8])(void);
void (*wakeupCallbacks[8])(void);
void (*finalizeCallbacks[8])(void);

nn::applet::CTR::SysSleepAcceptedCallbackInfo sleepCallbackInfo(0, 0, CTR::Sleep, 0, 0x8000);

const u32 currentProcess = 0xFFFF8001;
const u32 zero = 0;
const char dspServiceName[] = "dsp::DSP";

namespace CTR {

/* Functions that might/should exist, but haven't been found */
// Result LockComponent(void);
// Result UnlockComponent(void);
// Result InvalidateDataCache(u32, u32);
// void ClearSleepWakeUpCallback(void(*)(void), void(*)(void), void(*)(void));
// void Finalize(void);

#ifdef NON_MATCHING
Result FlushDataCache(u32 address, u32 size) {
    Result result(0xC8A0A7F8);

    if (session != NULL) {
        const u32* handle = &currentProcess;
        return session->FlushDataCache(*handle, address, size);
    }
    return Result(0xC8A0A7F8);
}
#else
GLOBAL_ASM("binary/_ZN2nn3dsp3CTR14FlushDataCacheEjj.o")
#endif

s8 IsComponentLoaded(void) {
    return isComponentLoaded;
}

void Sleep(void) {
    bool8 isAwake = isComponentLoaded & ~isAsleep;
    if (isAwake) {
        for (int i = 0; i < 8; i++) {
            if (sleepCallbacks[i] != NULL) {
                sleepCallbacks[i]();
            }
        }
        if (isComponentLoaded) {
            session->UnloadComponent();
            isComponentLoaded = false;
        } else {
            isComponentLoaded = false;
        }
        isAwake = returnTrueBool8(isFinalized);
        isAsleep = isAwake;
    }
    wereSleepCallbacksCalled = isAwake;
}

void OrderToWaitForFinalize(void) {
    if (isAsleep) {
        isFinalized = true;
        for (s32 i = 0; i < 8; i++) {
            if (finalizeCallbacks[i] != NULL) {
                finalizeCallbacks[i]();
            }
        }
        isAsleep = false;
    }
}

void Awake(void) {
    if (wereSleepCallbacksCalled) {
        WakeUp();
    }
}

inline Result LoadComponent(const u8* component, u32 componentSize, u16 programMask, u16 dataMask, bool8* componentIsLoaded) {
    Result result;
    if ((session != NULL) && (!isComponentLoaded)) {
        result = session->LoadComponent(component, componentSize, programMask, dataMask, componentIsLoaded);
    } else {
        result.SetCode(0xC8A0A7FCU);
    }
    return result;
}

void WakeUp(void) {
    Result result;
    u32 uVar1;

    wereSleepCallbacksCalled = false;
    if (isAsleep) {
        result = LoadComponent((u8*)registeredComponent, registeredComponentSize, registeredProgramMask, registeredDataMask, &isComponentLoaded);
        uVar1 = result.GetCode() >> 0x1B;

        if (result.GetCode() & 0x80000000) {
            uVar1 -= 0x20;
        }
        if ((uVar1 != ~0x6) && (uVar1 != 0) && (uVar1 != 1)) {
            nn::err::CTR::ThrowFatalErr(result);
        }
        for (s32 i = 0; i < 8; i++) {
            if (wakeupCallbacks[i] != NULL) {
                wakeupCallbacks[i]();
            }
        }
        isAsleep = false;
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

    if (session != NULL) {
        result.SetCode(0);
    } else {
        result = nn::srv::Initialize();
        if (!GetTopBit(result)) {
            Handle* handle = &sessionHandle;

            nameLen = std::strlen(dspServiceName);
            result = nn::srv::GetServiceHandle(handle, dspServiceName, nameLen, 0);
            if (!GetTopBit(result)) {
                (session = &sessionObject);
                session->SetHandle(sessionHandle);
                for (u32 i = 0; i < 8; i++) {
                    finalizeCallbacks[i] = NULL;
                    wakeupCallbacks[i] = NULL;
                    sleepCallbacks[i] = NULL;
                }
                isComponentLoaded = false;
                registeredComponent = NULL;
                registeredComponentSize = 0;
                registeredProgramMask = 0;
                registeredDataMask = 0;
                isAsleep = false;
                isFinalized = false;
                sleepCallbackInfo.Register();
                result.SetCode(0);
            }
        }
    }
    return result;
}

Result SetSemaphore(u16 value) {
    Result result;
    result.SetCode(0xC8A0A7F8);

    if (session != NULL) {
        return session->SetSemaphore(value);
    } else {
        return result;
    }
}

Result RecvDataIsReady(u16 registerNum, bool* outIsReady) {
    Result result;
    result.SetCode(0xC8A0A7F8);

    if (session != NULL) {
        return session->RecvDataIsReady(registerNum, outIsReady);
    } else {
        return result;
    }
}

void UnloadComponent(void) {
    bool8 isAwake = isComponentLoaded & ~isAsleep;
    if (isAwake) {
        for (int i = 0; i < 8; i++) {
            if (sleepCallbacks[i] != NULL) {
                sleepCallbacks[i]();
            }
        }
        if (isComponentLoaded) {
            session->UnloadComponent();
            isComponentLoaded = false;
        } else {
            isComponentLoaded = false;
        }
        isAwake = returnTrueBool8(isFinalized);
        isAsleep = isAwake;
    }
}

Result WriteProcessPipe(s32 channel, const u8* buffer, u32 size) {
    Result result;
    result.SetCode(0xC8A0A7F8);

    if (session != NULL) {
        return session->WriteProcessPipe(channel, buffer, size);
    } else {
        return result;
    }
}


Result ReadPipeIfPossible(s32 channel, u8* buffer, u16 size, u16* outLengthRead) {
    Result result;
    result.SetCode(0xC8A0A7F8);

    if (session != NULL) {
        return session->ReadPipeIfPossible(channel, 0, buffer, size, outLengthRead);
    } else {
        return result;
    }
}

Result SetSemaphoreEventMask(u16 mask) {
    Result result;
    result.SetCode(0xC8A0A7F8);

    if (session != NULL) {
        return session->SetSemaphoreMask(mask);
    } else {
        return result;
    }
}

Result GetSemaphoreEventHandle(Handle* outHandle) {
    Result result;
    result.SetCode(0xC8A0A7F8);

    if (session != NULL) {
        return session->GetSemaphoreEventHandle(outHandle);
    } else {
        return result;
    }
}

Result RegisterInterruptEvents(Handle handle, s32 interrupt, s32 channel) {
    Result result;
    result.SetCode(0xC8A0A7F8);

    if (session != NULL) {
        if (handle.Value() != 0) {
            if (!(eventUsedFlags & (1 << (interrupt + channel)))) {
                result = session->RegisterInterruptEvents(handle, interrupt, channel);
                eventUsedFlags |= (1 << (interrupt + channel));
            }
        } else {
            if (eventUsedFlags & (1 << (interrupt + channel))) {
                result = session->RegisterInterruptEvents(handle, interrupt, channel);
                eventUsedFlags &= ~(1 << (interrupt + channel));
            }
        }
    }
    return result;
}

bool RegisterSleepWakeUpCallback(void(*sleepCallback)(void), void(*wakeUpCallback)(void) , void(*finalizeCallback)(void)) {
    for (s32 i = 0; i < 8; i++) {
        if (sleepCallbacks[i] == NULL) {
            sleepCallbacks[i] = sleepCallback;
            wakeupCallbacks[i] = wakeUpCallback;
            finalizeCallbacks[i] = finalizeCallback;
            return true;
        }
    }
    return false;
}

Result ConvertProcessAddressFromDspDram(u32 address, u32* outAddress) {
    Result result;
    *outAddress = 0xFFFFFFFF;
    result.SetCode(0xC8A0A7F8);

    if (session != NULL) {
        session->ConvertProcessAddressFromDspDram(address, outAddress);
    }
    return result;
}

Result RecvData(u16 registerNumber, u16* outRegisterValue) {
    Result result;
    result.SetCode(0xC8A0A7F8);

    if (session != NULL) {
        return session->RecvData(registerNumber, outRegisterValue);
    } else {
        return result;
    }
}

Result GetHeadphoneStatus(bool* outStatus) {
    Result result;

    if (session != NULL) {
        return session->GetHeadphoneStatus(outStatus);
    } else {
        result.SetCode(0xC820A7F8);
        return result;
    }
}

} // namespace CTR
} // namespace dsp
} // namespace nn
