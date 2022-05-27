#include <nn/matching_tricks.hpp>

extern "C" {

/**
 * NOTE! This function is hardcoded as a partial inline for the sake of matching.
 * If you change this function, you MUST compile with NON_MATCHING set, or your
 * changes will not be reflected throughout the codebase!
 */
bool8 returnTrueBool8(u8) {
    return true;
}

}
