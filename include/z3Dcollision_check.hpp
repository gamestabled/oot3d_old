#ifndef _Z_COLLISION_CHECK_H_
#define _Z_COLLISION_CHECK_H_

#include "z3Dmath.hpp"

struct Actor;

typedef struct {
    /* 0x00 */ struct Actor* actor; // Attached actor
    /* 0x04 */ struct Actor* at; // Actor attached to what it collided with as an AT collider.
    /* 0x08 */ struct Actor* ac; // Actor attached to what it collided with as an AC collider.
    /* 0x0C */ struct Actor* oc; // Actor attached to what it collided with as an OC collider.
    /* 0x10 */ u8 atFlags; // Information flags for AT collisions. 
    /* 0x11 */ u8 acFlags; // Information flags for AC collisions.
    /* 0x12 */ u8 ocFlags1; // Information flags for OC collisions.
    /* 0x13 */ u8 ocFlags2;  // Flags related to which colliders it can OC collide with.
    /* 0x14 */ u8 colType; // Determines hitmarks and sound effects during AC collisions.
    /* 0x15 */ u8 shape; // JntSph, Cylinder, Tris, or Quad
} Collider; // size = 0x18

typedef struct {
    /* 0x00 */ u8 colType; // Determines hitmarks and sound effects during AC collisions.
    /* 0x01 */ u8 atFlags; // Information flags for AT collisions. 
    /* 0x02 */ u8 acFlags; // Information flags for OC collisions.
    /* 0x03 */ u8 ocFlags1; // Information flags for OC collisions.
    /* 0x04 */ u8 ocFlags2; // Flags related to which colliders it can OC collide with.
    /* 0x05 */ u8 shape; // JntSph, Cylinder, Tris, or Quad
} ColliderInit; // size = 0x06

typedef struct {
    /* 0x00 */ u32 dmgFlags; // Toucher damage type flags.
    /* 0x04 */ u8 effect; // Damage Effect (Knockback, Fire, etc.)
    /* 0x05 */ u8 damage; // Damage or Stun Timer
} ColliderTouch; // size = 0x08

typedef struct {
    /* 0x00 */ u32 dmgFlags;  // Bumper damage type flags.
    /* 0x04 */ u8 effect;  // Damage Effect (Knockback, Fire, etc.)
    /* 0x05 */ u8 defense; // Damage Resistance
    /* 0x06 */ Vec3s hitPos; // Point of contact
} ColliderBump; // size = 0x0C

typedef struct {
    /* 0x00 */ u32 dmgFlags; // Bumper exclusion mask
    /* 0x04 */ u8 effect; // Damage Effect (Knockback, Fire, etc.)
    /* 0x05 */ u8 defense; // Damage Resistance
} ColliderBumpInit; // size = 0x08

typedef struct ColliderInfo {
    /* 0x00 */ ColliderTouch toucher; // Damage properties when acting as an AT collider
    /* 0x08 */ ColliderBump bumper; // Damage properties when acting as an AC collider
    /* 0x14 */ u8 elemType; // Affects sfx reaction when attacked by Link and hookability. Full purpose unknown.
    /* 0x15 */ u8 toucherFlags; // Information flags for AT collisions
    /* 0x16 */ u8 bumperFlags; // Information flags for AC collisions
    /* 0x17 */ u8 ocElemFlags; // Information flags for OC collisions
    /* 0x18 */ Collider* atHit;                // object touching this element's AT collider
    /* 0x1C */ Collider* acHit;                // object touching this element's AC collider
    /* 0x20 */ struct ColliderInfo* atHitInfo; // element that hit the AT collider
    /* 0x24 */ struct ColliderInfo* acHitInfo; // element that hit the AC collider
} ColliderInfo; // size = 0x28

typedef struct {
    /* 0x00 */ u8 elemType; // Affects sfx reaction when attacked by Link and hookability. Full purpose unknown.
    /* 0x04 */ ColliderTouch toucher; // Damage properties when acting as an AT collider
    /* 0x0C */ ColliderBumpInit bumper; // Damage properties when acting as an AC collider
    /* 0x14 */ u8 toucherFlags; // Information flags for AT collisions
    /* 0x15 */ u8 bumperFlags;  // Information flags for AC collisions
    /* 0x16 */ u8 ocElemFlags; // Information flags for OC collisions
} ColliderInfoInit; // size = 0x18

typedef struct {
    /* 0x00 */ Collider base;
    /* 0x18 */ ColliderInfo info;
    /* 0x40 */ Cylinderf dim;
} ColliderCylinder; // size = 0x58

typedef struct {
    /* 0x00 */ ColliderInit base;
    /* 0x08 */ ColliderInfoInit info;
    /* 0x20 */ Cylinderf dim;
} ColliderCylinderInit; // size = 0x2C

#endif
