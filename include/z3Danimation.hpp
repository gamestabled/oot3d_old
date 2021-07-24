#ifndef _Z3DANIMATION_H_
#define _Z3DANIMATION_H_

#include "z3Dvec.hpp"

typedef struct SkelAnime {
    /* 0x00 */ void* unk_00;
    /* 0x04 */ struct ZARInfo* zarInfo;
    /* 0x08 */ char unk_08[0x08];
    /* 0x10 */ struct GlobalContext* globalCtx;
    /* 0x14 */ char unk_14[0x14];
    /* 0x28 */ struct SkeletonAnimationModel* unk_28;
    /* 0x2C */ char unk_2C[0x4];
    /* 0x30 */ s32 animationType;
    /* 0x34 */ char unk_34[0x8];
    /* 0x3C */ f32 curFrame;
    /* 0x40 */ f32 playSpeed;
    /* 0x44 */ f32 startFrame;
    /* 0x48 */ f32 endFrame;
    /* 0x4C */ f32 animLength;
    /* 0x50 */ char unk_50[0x24];
    /* 0x74 */ u8 limbCount;
    /* 0x75 */ char unk_75[0x03];
    /* 0x78 */ void* jointTable;
    /* 0x7C */ void* morphTable;
    /* 0x80 */ char unk_80[0x02];
    /* 0x82 */ u8 tablesAllocated;
    /* 0x83 */ char unk_83[0x01];
} SkelAnime; // size = 0x84

#endif
