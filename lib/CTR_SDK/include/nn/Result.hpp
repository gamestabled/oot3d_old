#ifndef _NN_RESULT_H_
#define _NN_RESULT_H_

#include "types.hpp"

namespace nn {

class Result {
public:
    Result() {}

    Result(u32 code) : _code(code) {
        // _code = code;
    }

    void SetCode(u32 code) {
        _code = code;
    }

    u32 GetCode(void) const {
        return _code;
    }

private:
    u32 _code;
};

} //namespace nn
#endif //_NN_RESULT_H_
