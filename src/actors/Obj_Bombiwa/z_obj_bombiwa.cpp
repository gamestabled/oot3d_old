extern "C" {
#include "z_obj_bombiwa.hpp"

#define FLAGS 0x00000000

void ObjBombiwa_Init(Actor* actor, GameState* state);
void ObjBombiwa_Destroy(Actor* actor, GameState* state);
void ObjBombiwa_Update(Actor* actor, GameState* state);
void ObjBombiwa_Draw(Actor* actor, GameState* state);

ActorInit Obj_Bombiwa_InitVars = {
    ACTOR_OBJ_BOMBIWA,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_BOMBIWA,
    sizeof(ObjBombiwa),
    (ActorFunc)ObjBombiwa_Init,
    (ActorFunc)ObjBombiwa_Destroy,
    (ActorFunc)ObjBombiwa_Update,
    (ActorFunc)ObjBombiwa_Draw,
};

static CollisionCheckInfoInit sColChkInfoInit = { 0, 12, 60, 0xFF };

static ColliderCylinderInit sCylinderInit = {
    {
        0xC,
        0x0,
        0xD,
        0x39,
        0x20,
        0x01,
    },
    {
        0,
        { 0x00000000, 0x00, 0x00 },
        { 0x4FC1FFFE, 0x00, 0x00 },
        0,
        1,
        1,
    },
    { 55.0f, 70.0f, 0, { 0 } },
};

static InitChainEntry sInitChain[] = {
    ICHAIN_VEC3F_DIV1000(scale, 100, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneForward, 2000, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneScale, 350, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneDownward, 1000, ICHAIN_STOP),
};

// This is getting optimized out so im including it in the next data chunk
static s16 sEffectScales[] = {
    17, 14, 10, 8, 7, 5, 3, 2,
};

inline void ObjBombiwa_InitCollision(ObjBombiwa* self, GlobalContext* globalCtx) {
    Collider_InitCylinder(globalCtx, &self->collider);
    Collider_SetCylinder(globalCtx, &self->collider, &self->actor, &sCylinderInit);
    Collider_UpdateCylinder(&self->actor, &self->collider);
}

void ObjBombiwa_Init(Actor* actor, GameState* state) {
    ObjBombiwa* self = (ObjBombiwa*)actor;
    GlobalContext* globalCtx = (GlobalContext*)state;

    Actor_ProcessInitChain(&self->actor, sInitChain);
    FUN_00372f38(&self->actor, globalCtx, &self->skelAnimModel, 0, 0);
    ObjBombiwa_InitCollision(self, globalCtx);
    if ((Flags_GetSwitch(globalCtx, self->actor.params & 0x3F) != 0)) {
        Actor_Kill(&self->actor);
    } else {
        CollisionCheck_SetInfo(&self->actor.colChkInfo, (DamageTable*)NULL, &sColChkInfoInit);
        if (self->actor.shape.rot.y == 0) {
            s16 rand = (s16)Rand_ZeroFloat(65536.0f);
            self->actor.world.rot.y = rand;
            self->actor.shape.rot.y = rand;
        }
        self->actor.shape.yOffset = -200.0f;
        self->actor.world.pos.y = self->actor.home.pos.y + 20.0f;
    }
}

void ObjBombiwa_Destroy(Actor* actor, GameState* state) {
    ObjBombiwa* self = (ObjBombiwa*)actor;
    GlobalContext* globalCtx = (GlobalContext*)state;

    Collider_DestroyCylinder(globalCtx, &self->collider);
    FUN_00350f34(&self->actor, &self->skelAnimModel, 0);
}
}
