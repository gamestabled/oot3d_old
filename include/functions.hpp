#pragma once
#include "z3D.hpp"

void ActorShape_Init(ActorShape* shape, f32 yOffset, ActorShadowFunc shadowDraw, f32 shadowScale);
void ActorShadow_DrawCircle(Actor* actor, Lights* lights, GlobalContext* globalCtx);

Actor* Actor_Find(ActorContext* actorCtx, s32 actorId, s32 actorCategory);

PosRot Actor_GetWorldPosShapeRot(Actor* actor);
s32 Actor_HasNoParent(Actor* actor, GlobalContext* globalCtx);
s32 Actor_HasParent(Actor* actor, GlobalContext* globalCtx);
s32 Actor_IsFacingAndNearPlayer(Actor* actor, f32 range, s16 angle);
s32 Actor_IsMounted(GlobalContext *globalCtx, Actor *horse);
void Actor_Kill(Actor* actor);
void Actor_Noop(Actor* actor, GameState* state);
s32 Actor_NotMounted(GlobalContext *globalCtx, Actor *actor);
void Actor_ProcessInitChain(Actor* actor, InitChainEntry* chain);
void Actor_SetFocus(Actor* actor, f32 yOffset);
s32 Actor_SetRideActor(GlobalContext* globalCtx, Actor* horse, s32 mountSide);
void Actor_SetScale(Actor* actor, f32 scale);
Actor* Actor_Spawn(ActorContext* actorCtx, GlobalContext* globalCtx, s16 actorId, f32 posX, f32 posY, f32 posZ,
                   s16 rotX, s16 rotY, s16 rotZ, s16 params, s32 unk);
void Actor_UpdateBgCheckInfo(GlobalContext* globalCtx, Actor* actor, f32 wallCheckHeight, f32 wallCheckRadius,
                             f32 ceilingCheckHeight, s32 flags);
f32 Actor_WorldDistXYZToActor(Actor* actorA, Actor* actorB);

void Math_ApproachS(s16* pValue, s16 target, s16 scale, s16 step);
void Math_ApproachF(f32* pValue, f32 target, f32 fraction, f32 step);
void Math_ApproachZeroF(f32* pValue, f32 fraction, f32 step);
f32 Math_CosS(s16 angle);
f32 Math_FAtan2F(f32 y, f32 x);
f32 Math_SinS(s16 angle);
void Math_Vec3f_Copy(Vec3f* dest, Vec3f* src);
f32 Math_Vec3f_DistXYZ(Vec3f* a, Vec3f* b);
void Math_Vec3s_ToVec3f(Vec3f* dest, Vec3s* src);

ZARInfo* FUN_00372f38(Actor* actor, GlobalContext* globalCtx, SkeletonAnimationModel** skelAnimModel, s32 arg3,
                      s32 arg4);
void FUN_00350f34(Actor* actor, SkeletonAnimationModel** skelAnimModel, s32 arg2);
void MTX34CopyAsm(MTX34* dst, MTX34* src);
void FUN_00370734(SkelAnime* skelAnime);
Camera* Gameplay_GetCamera(GlobalContext* globalCtx, s16 camId);
void FUN_00367494(GlobalContext* globalCtx, CutsceneContext* csCtx);
s32 FUN_0036e980(GlobalContext* globalCtx, Actor* actor, u8 arg2);
s16 Gameplay_CreateSubCamera(GlobalContext* globalCtx);
s16 Gameplay_ChangeCameraStatus(GlobalContext* globalCtx, s16 camId, s16 status);
void Audio_PlaySoundGeneral(u32 sfxId, Vec3f* a1, u8 a2, f32* a3, f32* a4, s8* a5);
void FUN_0035af04(Player* player, s32 arg1);
void Audio_QueueSeqCmd(s32 arg0, s32 arg1, s32 arg2);
void TitleCard_InitBossName(GlobalContext* globalCtx, TitleCardContext* titleCtx, void* texture, s16 x, s16 y,
                            s16 width, s16 height, f32 f);
void FUN_0036e9b8(GlobalContext* globalCtx, s16 camId, s16 arg2);
void FUN_00367374(GlobalContext* globalCtx, CutsceneContext* csCtx);
s32 Gameplay_CameraSetAtEye(GlobalContext* globalCtx, s16 camId, Vec3f* at, Vec3f* eye);
f32 Rand_ZeroFloat(f32 f);
void FUN_0036f5d8(GlobalContext* globalCtx, s16 arg1, s16 arg2, s16 arg3);
f32 Rand_CenteredFloat(f32 f);
void EffectSsKFire_Spawn(GlobalContext* globalCtx, Vec3f* pos, Vec3f* velocity, Vec3f* accel, s16 scaleMax, u8 type);
s32 FUN_0035b164(void);
s32 FUN_0035b0a0(void);
void FUN_0035af20(GlobalContext* globalCtx, s32 arg1, s16 arg2, s16 arg3, f32 f0, f32 f1, f32 f2, f32 f3, f32 f4,
                  f32 f5);
void FUN_00365860(Actor* actor);
void FUN_0036b96c(Actor* actor);
void FUN_003731e0(SkelAnime* skelAnime);
void FUN_0036788c(void* arg0);
void FUN_003542c4(void* arg0, s32 arg1, s32 arg2);
s32 Collider_InitCylinder(GlobalContext* globalCtx, ColliderCylinder* collider);
s32 Collider_DestroyCylinder(GlobalContext* globalCtx, ColliderCylinder* collider);
s32 Collider_SetCylinder(GlobalContext* globalCtx, ColliderCylinder* collider, Actor* actor, ColliderCylinderInit* src);
void Collider_UpdateCylinder(Actor* actor, ColliderCylinder* collider);
void CollisionCheck_SetInfo(CollisionCheckInfo* info, DamageTable* damageTable, CollisionCheckInfoInit* init);
void CollisionCheck_SetInfo2(CollisionCheckInfo* info, DamageTable* damageTable, CollisionCheckInfoInit2* init);
void SkelAnime_Free(SkelAnime* skelAnime, GlobalContext* globalCtx);
void SkelAnime_Free2(SkelAnime* skelAnime);

s32 Flags_GetSwitch(GlobalContext* globalCtx, s32 flag);
void Flags_SetSwitch(GlobalContext* globalCtx, s32 flag);
void Flags_UnsetSwitch(GlobalContext* globalCtx, s32 flag);
s32 Flags_GetTreasure(GlobalContext* globalCtx, s32 flag);
void Flags_SetTreasure(GlobalContext* globalCtx, s32 flag);
s32 Flags_GetClear(GlobalContext* globalCtx, s32 flag);
void Flags_SetClear(GlobalContext* globalCtx, s32 flag);
void Flags_UnsetClear(GlobalContext* globalCtx, s32 flag);
s32 Flags_GetTempClear(GlobalContext* globalCtx, s32 flag);
void Flags_SetTempClear(GlobalContext* globalCtx, s32 flag);
s32 Flags_GetCollectible(GlobalContext* globalCtx, s32 flag);
void Flags_SetCollectible(GlobalContext* globalCtx, s32 flag);
s32 Flags_GetEventChkInf(s32 flag);
void Flags_SetEventChkInf(s32 flag);

Actor* FUN_00346d94(GlobalContext* globalCtx, Actor* explosiveActor);
s32 CollisionCheck_SetAC(GlobalContext* globalCtx, CollisionCheckContext* colChkCtx, Collider* collider);
s32 CollisionCheck_SetOC(GlobalContext* globalCtx, CollisionCheckContext* colChkCtx, Collider* collider);
f32 Rand_ZeroOne(void);
void EffectSsKakera_Spawn(GlobalContext* globalCtx, Vec3f* pos, Vec3f* velocity, Vec3f* arg3, s16 gravity, s16 arg5,
                          s16 arg6, s16 arg7, s16 arg8, s16 scale, s16 arg10, s16 arg11, s32 life, s16 colorIdx,
                          s16 objId, void* dList);
void FUN_0037378c(GlobalContext* globalCtx, Vec3f* arg1, f32 arg2, s32 arg3, s16 arg4, s16 arg5, u8 arg6);
void Audio_PlaySoundAtPosition(GlobalContext* globalCtx, Vec3f* pos, s32 duration, u32 sfxId);
void FUN_00372244(void* arg0, s16 arg1, u32 sfxId);
s32 GiveItem(Actor* actor, GlobalContext* globalCtx, s32 getItemId, f32 xyRange, f32 yRange);
void DynaPolyActor_Init(DynaPolyActor* dynaActor, s32 flags);
ZARInfo* FUN_003532c0(ZARInfo* zarInfo, s32 arg1);
s32 DynaPoly_SetBgActor(GlobalContext* globalCtx, DynaCollisionContext* dyna, Actor* actor, CollisionHeader colHeader);
void DynaPoly_DeleteBgActor(GlobalContext* globalCtx, DynaCollisionContext* dyna, s32 bgId);

void FUN_003695cc(SkeletonAnimationModel* skelAnimModel, s32 arg1, s32 arg2, s32 arg3, f32 arg4, f32 arg5, f32 arg6,
                  f32 arg7);
s32 FUN_00369f3c(GlobalContext* globalCtx);
void EffectSsHahen_SpawnBurst(GlobalContext* globalCtx, Vec3f* pos, f32 burstScale, s16 unused, s16 scale,
                              s16 randScaleRange, s16 count, s16 objId, s16 life, void* dList);
void FUN_003716f0(GlobalContext* globalCtx, s16 entranceIndex, u32 sceneLoadFlag, u32 fadeTransition);
s32 Math3D_PointInSquare2D(f32 upperLeftX, f32 lowerRightX, f32 upperLeftY, f32 lowerRightY, f32 x, f32 y);
void FUN_0035239c(s16 arg0);
void FUN_00367c7c(GlobalContext*, u16 textID, Actor* actor);
void Audio_QueueSeqCmd(s32 arg0, s32 arg1, s32 arg2);
void FUN_00354358(s32 arg0);

float sqrtf(float arg);
