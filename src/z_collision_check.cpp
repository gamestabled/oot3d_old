extern "C" {
#include "z3D.hpp"
#include "math.hpp"
#include "functions.hpp"

static s32 Collider_DestroyBase(PlayState* play, Collider* collider) {
    return 1;
}

static s32 Collider_DestroyTouch(PlayState* play, ColliderTouch* touch) {
    return 1;
}

static s32 Collider_DestroyBump(PlayState* play, ColliderBump* bump) {
    return 1;
}

static s32 Collider_DestroyInfo(PlayState* play, ColliderInfo* info) {
    Collider_DestroyTouch(play, &info->toucher);
    Collider_DestroyBump(play, &info->bumper);
    return 1;
}

static s32 Collider_DestroyCylinderDim(PlayState* play, Cylinderf* dim) {
    return 1;
}

/**
 * Destroys a ColliderCylinder
 * 
 * NOTE! This function is hardcoded as a partial inline for the sake of matching.
 * If you change this function, you MUST compile with NON_MATCHING set, or your
 * changes will not be reflected throughout the codebase!
 */
s32 Collider_DestroyCylinder(PlayState* play, ColliderCylinder* collider) {
    Collider_DestroyBase(play, &collider->base);
    Collider_DestroyInfo(play, &collider->info);
    Collider_DestroyCylinderDim(play, &collider->dim);
    return 1;
}
}
