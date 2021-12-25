extern "C" {
#include "z_object_kankyo.hpp"

#define FLAGS 0x02000030

void ObjectKankyo_Init(Actor* actor, GameState* state);
void ObjectKankyo_Destroy(Actor* actor, GameState* state);
void ObjectKankyo_Update(Actor* actor, GameState* state);
void ObjectKankyo_Draw(Actor* actor, GameState* state);

GLOBAL_ASM("binary/z_Object_Kankyo.data.o")

/*
ActorInit Object_Kankyo_InitVars = {
    ACTOR_OBJECT_KANKYO,
    ACTORCAT_ITEMACTION,
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(ObjectKankyo),
    (ActorFunc)ObjectKankyo_Init,
    (ActorFunc)ObjectKankyo_Destroy,
    (ActorFunc)ObjectKankyo_Update,
    (ActorFunc)ObjectKankyo_Draw,
};
*/

GLOBAL_ASM("binary/ObjectKankyo_Init.o")

GLOBAL_ASM("binary/ObjectKankyo_Destroy.o")

GLOBAL_ASM("binary/ObjectKankyo_Update.o")

GLOBAL_ASM("binary/ObjectKankyo_Draw.o")
}
