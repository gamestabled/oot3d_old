#pragma once

#include <nn/Result.hpp>

namespace nn {
namespace applet {
namespace CTR {

struct SysSleepAcceptedCallbackInfo {
public:
    SysSleepAcceptedCallbackInfo(s32 arg0, s32 arg1, void(*arg2)(), s32 arg3, s32 arg4) : unk_0(arg0), unk_4(arg1), unk_8(arg2), unk_C(arg3), unk_10(arg4) {}

    void Register(void);
    void Unregister(void);

private:
    s32 unk_0;
    s32 unk_4;
    void(*unk_8)(void);
    s32 unk_C;
    s32 unk_10;
};

} // namespace CTR
} // namespace applet
} // namespace nn
