#include <nn/dsp.hpp>

#include <nn/err.hpp>
#include <nn/srv.hpp>
#include <nn/applet.hpp>

#include <std/cstring.hpp>

// class nn::dsp::CTR::DSP;
#include "non_matchings.hpp"

namespace nn {
namespace dsp {

// GLOBAL_ASM("binary/FUN_00412210.o") Static initialzier for dsp namespace

bool8 isSleepAcceptedCallbackCalled;
bool8 isComponentLoaded;
bool8 isSleeping;
ubool8 isWaitingForFinalize;

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

const u32 pseudoHandleCurrentProces = 0xFFFF8001;
const char dspServiceName[] __attribute__((aligned (8))) = "dsp::DSP";

namespace CTR {

// GLOBAL_ASM("binary/_ZN2nn3dsp3CTR17IsComponentLoadedEv.o")
s8 IsComponentLoaded(void) {
    return isComponentLoaded;
}

// GLOBAL_ASM("binary/_ZN2nn3dsp3CTR5SleepEv.o")
void Sleep(void) {
    bool8 isAwake = isComponentLoaded & ~isSleeping;
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
        isAwake = returnTrueBool8(isWaitingForFinalize);
        isSleeping = isAwake;
    }
    isSleepAcceptedCallbackCalled = isAwake;
}

// GLOBAL_ASM("binary/_ZN2nn3dsp3CTR22OrderToWaitForFinalizeEv.o")
void OrderToWaitForFinalize(void) {
    if (isSleeping) {
        isWaitingForFinalize = true;
        for (s32 i = 0; i < 8; i++) {
            if (finalizeCallbacks[i] != NULL) {
                finalizeCallbacks[i]();
            }
        }
        isSleeping = false;
    }
}

// GLOBAL_ASM("binary/_ZN2nn3dsp3CTR5AwakeEv.o")
void Awake(void) {
    if (isSleepAcceptedCallbackCalled) {
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

// GLOBAL_ASM("binary/_ZN2nn3dsp3CTR6WakeUpEv.o")
void WakeUp(void) {
    Result result;
    u32 uVar1;

    isSleepAcceptedCallbackCalled = false;
    if (isSleeping) {
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
        isSleeping = false;
    }
}

// This seems to be an error check, for matching,
// it does need to be an inline'd helper like this.
// Does this belong in srv.hpp?
inline u32 GetTopBit(Result r) {
    return r.GetCode() >> 0x1F;
}

// GLOBAL_ASM("binary/_ZN2nn3dsp3CTR10InitializeEv.o")
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
                isSleeping = false;
                isWaitingForFinalize = false;
                sleepCallbackInfo.Register();
                result.SetCode(0);
            }
        }
    }
    return result;
}

// GLOBAL_ASM("binary/_ZN2nn3dsp3CTR12SetSemaphoreEt.o")
Result SetSemaphore(u16 value) {
    Result result;
    result.SetCode(0xC8A0A7F8);

    if (session != NULL) {
        return session->SetSemaphore(value);
    } else {
        return result;
    }
}

// Result LockComponent(void);

// struct test {
//     Handle unk0;
//     u32 unk1;
// };

// extern const test thing;

GLOBAL_ASM("binary/_ZN2nn3dsp3CTR14FlushDataCacheEjj.o")
// Result FlushDataCache(u32 address, u32 size) {
//     Result result;
//     result.SetCode(0xC8A0A7F8);
//     // DSP* temp = session;

//     u32 s = size;
//     if (session != NULL) {
//         return session->FlushDataCache(thing.unk0, address, s);
//         // return result;
//     } else {
//         return result;
//     }
// }

// Result RecvDataIsReady(u16, bool*);
// Result UnloadComponent(void);
// Result UnlockComponent(void);
// Result WriteProcessPipe(s32, const void*, u32);
// Result ReadPipeIfPossible(s32, void*, u16, u16*);
// Result InvalidateDataCache(u32, u32);
// Result SetSemaphoreEventMask(u16);
// Result GetSemaphoreEventHandle(Handle);
// Result RegisterInterruptEvents(Handle, s32, s32);
// void ClearSleepWakeUpCallback(void(*)(void), void(*)(void), void(*)(void));
// bool RegisterSleepWakeUpCallback(void(*)(void), void(*)(void), void(*)(void));
// Result ConvertProcessAddressFromDspDram(u32, u32*);
// void Finalize(void);
// Result RecvData(u16, u16*);
// Result GetHeadphoneStatus(bool*);

} // namespace CTR
} // namespace dsp
} // namespace nn
