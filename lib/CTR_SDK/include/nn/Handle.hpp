#ifndef _NN_HANDLE_H_
#define _NN_HANDLE_H_

#include "types.hpp"

namespace nn {

class Handle {
public:
    Handle() {}
    Handle(u32 handle) : _handle(handle) {}

private:
    u32 _handle;
};

} //namespace nn

#endif //_NN_HANDLE_H_
