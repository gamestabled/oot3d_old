#pragma once
#include "z3D.hpp"

Actor* Actor_Spawn(ActorContext* actorCtx, GlobalContext* globalCtx, s16 actorId, f32 posX, f32 posY, f32 posZ,
                   s16 rotX, s16 rotY, s16 rotZ, s16 params, s32 unk);
void Actor_Kill(Actor* actor);
void Actor_SetScale(Actor* actor, f32 scale);
ZARInfo* FUN_00372f38(Actor* actor, GlobalContext* globalCtx, SkeletonAnimationModel** skelAnimModel, s32 arg3, s32 arg4);
void FUN_00350f34(Actor* actor, SkeletonAnimationModel** skelAnimModel, s32 arg2);
void MTX34CopyAsm(nn_math_MTX34* dst, nn_math_MTX34* src);
void FUN_003721e0(SkeletonAnimationModel* skelAnimModel, nn_math_MTX34* modelMtx);
void FUN_00372170(SkeletonAnimationModel* skelAnimModel, s32 arg1);
