#pragma once

#include <nn/Handle.hpp>
#include <nn/Result.hpp>

namespace nn {
namespace dsp {
namespace CTR {

void OrderToWaitForFinalize(void);
s8 IsComponentLoaded(void);
void Awake(void);
void Sleep(void);
void WakeUp(void) __attribute__((noinline));
Result Initialize(void);
Result SetSemaphore(u16);
Result LoadComponent(const u8*, u32, u16, u16, bool*);
Result LockComponent(void);
Result FlushDataCache(u32, u32);
Result RecvDataIsReady(u16, bool*);
void UnloadComponent(void);
Result UnlockComponent(void);
Result WriteProcessPipe(s32, const void*, u32);
Result ReadPipeIfPossible(s32, void*, u16, u16*);
Result InvalidateDataCache(u32, u32);
Result SetSemaphoreEventMask(u16);
Result GetSemaphoreEventHandle(Handle*);
Result RegisterInterruptEvents(Handle, s32, s32);
void ClearSleepWakeUpCallback(void(*)(void), void(*)(void), void(*)(void));
bool RegisterSleepWakeUpCallback(void(*)(void), void(*)(void), void(*)(void));
Result ConvertProcessAddressFromDspDram(u32, u32*);
void Finalize(void);
Result RecvData(u16, u16*);
Result GetHeadphoneStatus(bool*);

class DSP {
public:
    Result LoadComponent(const u8*, u32, u16, u16, bool8*);
    Result UnloadComponent(void);
    Result ForceHeadphoneOut(bool);
    Result SetSemaphore(u16);
    Result FlushDataCache(Handle, u32, u32);
    Result RecvDataIsReady(u16, bool*);
    Result SetSemaphoreMask(u16);
    Result WriteProcessPipe(s32, const u8*, u32);
    Result ReadPipeIfPossible(s32, s32, u8*, u16, u16*);
    Result InvalidateDataCache(Handle, u32, u32);
    Result GetSemaphoreEventHandle(Handle*);
    Result RegisterInterruptEvents(Handle, s32, s32);
    Result ConvertProcessAddressFromDspDram(u32, u32*);
    Result RecvData(u16, u16*);
    Result GetHeadphoneStatus(bool*);

    void SetHandle(Handle handle) {
        _handle = handle;
    }
private:
    Handle _handle;
};

// This should be INVALID_HANDLE_VALUE which is included
// from Handle.hpp. But, it gets optimized out, so this is
// kind of fake to get the data to match.
extern const u32 zero;

} // namespace CTR
} // namespace dsp
} // namespace nn
