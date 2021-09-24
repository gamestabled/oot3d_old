extern "C" {
#include "z3D.hpp"
#include "math.hpp"
#include "functions.hpp"

static s32 Collider_DestroyBase(GlobalContext* globalCtx, Collider* collider) {
    return 1;
}

static s32 Collider_DestroyTouch(GlobalContext* globalCtx, ColliderTouch* touch) {
    return 1;
}

static s32 Collider_DestroyBump(GlobalContext* globalCtx, ColliderBump* bump) {
    return 1;
}

static s32 Collider_DestroyInfo(GlobalContext* globalCtx, ColliderInfo* info) {
    Collider_DestroyTouch(globalCtx, &info->toucher);
    Collider_DestroyBump(globalCtx, &info->bumper);
    return 1;
}

static s32 Collider_DestroyCylinderDim(GlobalContext* globalCtx, Cylinderf* dim) {
    return 1;
}

/**
 * Destroys a ColliderCylinder
 * 
 * NOTE! This function is hardcoded as a partial inline for the sake of matching.
 * If you change this function, you MUST compile with NON_MATCHING set, or your
 * changes will not be reflected throughout the codebase!
 */
s32 Collider_DestroyCylinder(GlobalContext* globalCtx, ColliderCylinder* collider) {
    Collider_DestroyBase(globalCtx, &collider->base);
    Collider_DestroyInfo(globalCtx, &collider->info);
    Collider_DestroyCylinderDim(globalCtx, &collider->dim);
    return 1;
}
}
