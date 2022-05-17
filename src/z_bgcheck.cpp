extern "C" {
#include "z3Dbgcheck.hpp"

/**
 * NOTE! This function is hardcoded as a partial inline for the sake of matching.
 * If you change this function, you MUST compile with NON_MATCHING set, or your
 * changes will not be reflected throughout the codebase!
 */
void ReadCollisionHeaderFromZsi(void* arg1, CollisionHeader** col) {
    *col = (CollisionHeader*) arg1;
}
}