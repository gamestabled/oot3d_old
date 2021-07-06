#include "../z3Dvec.hpp"

namespace nn {
namespace err {
namespace CTR {

typedef u8 ErrorType;
typedef u8 ExceptionType;
typedef u32 Result;

struct Failure {
    char message[96];
};

struct CPURegisters {
    u32 r[13];
    u32 sp;
    u32 lr;
    u32 pc;
    u32 cpsr;
};

struct ExceptionInfo {
    ExceptionType exception_type;
    u32 status_register;
    u32 reg;
    u32 fpexc;
    u32 fpinst;
    u32 fpinst2;
};

struct Exception {
    ExceptionInfo info;
    CPURegisters cpu_registers;
};

struct ExceptionData {
    Exception exception;
    Failure failure;
};

struct FatalErrInfo {
    ErrorType error_type;
    u8 revision_hi;
    u8 revision_lo;
    Result result;
    u32 link_register;
    u32 process_id;
    u64 title_id;
    u64 applet_title_id;
    ExceptionData data;

};

// extern FatalErrInfo sFatalErrInfo;

// void ThrowFatalError(Result result) {
// }

} // namespace CTR
} // namespace err
} // namespace nn
