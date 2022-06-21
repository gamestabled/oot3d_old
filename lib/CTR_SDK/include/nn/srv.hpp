#pragma once

#include <nn/Result.hpp>
#include <nn/Handle.hpp>

namespace nn {
namespace srv {

Result Initialize(void);
Result GetServiceHandle(Handle* outHandle, const char* name, u32 nameLen, u32 flags);

namespace CTR {

} // namespace CTR
} // namespace err
} // namespace nn
