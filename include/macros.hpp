#ifndef _MACROS_H_
#define _MACROS_H_

#define ARRAY_COUNT(arr) (s32)(sizeof(arr) / sizeof(arr[0]))
#define ARRAY_COUNTU(arr) (u32)(sizeof(arr) / sizeof(arr[0]))

#define SQ(x) ((x)*(x))
#define ABS(x) ((x) >= 0 ? (x) : -(x))

#define LINK_IS_ADULT (gSaveContext.linkAge == 0)
#define LINK_IS_CHILD (gSaveContext.linkAge == 1)

#define GET_PLAYER(globalCtx) ((Player*)(globalCtx)->actorCtx.actorLists[ACTORCAT_PLAYER].head)

#define ADJUST_F32_FOR_FRAMERATE(f) ((2.0f * f) / 3.0f)
#define ADJUST_S32_FOR_FRAMERATE(s) ((3 * s) / 2)

#define ADJUST_FRAMECOUNT(x) ((s32)((f32)(3 * x) / SREG(30) + 0.5f))

#endif
