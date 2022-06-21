#ifndef _NN_HANDLE_H_
#define _NN_HANDLE_H_

#include "types.hpp"

namespace nn {

class Handle {
public:
    Handle() {}
    Handle(u32 handle) : _handle(handle) {}

    u32 Value(void) const {
        return _handle;
    }

private:
    u32 _handle;
};

namespace {
    const u32 PSEUDO_HANDLE_CURRENT_PROCESS = 0xFFFF8001;
    const u32 INVALID_HANDLE_VALUE = 0;
}

} //namespace nn

#endif //_NN_HANDLE_H_
