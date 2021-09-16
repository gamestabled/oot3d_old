extern "C" {
#include "global.hpp"

void SkelAnime_Free(SkelAnime* skelAnime, GlobalContext* globalCtx) {
    return SkelAnime_Free2(skelAnime);
}
}
