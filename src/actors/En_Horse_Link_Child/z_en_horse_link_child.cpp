extern "C" {
#include "z_en_horse_link_child.hpp"

#define FLAGS 0x02000010

void EnHorseLinkChild_Init(Actor* actor, GameState* state);
void EnHorseLinkChild_Destroy(Actor* actor, GameState* state);
void EnHorseLinkChild_Update(Actor* actor, GameState* state);
void EnHorseLinkChild_Draw(Actor* actor, GameState* state);

GLOBAL_ASM("binary/z_En_Horse_Link_Child.data.o")

ActorInit En_Horse_Link_Child_InitVars = {
    ACTOR_EN_HORSE_LINK_CHILD,
    ACTORCAT_BG,
    FLAGS,
    OBJECT_HORSE_LINK_CHILD,
    sizeof(EnHorseLinkChild),
    (ActorFunc)EnHorseLinkChild_Init,
    (ActorFunc)EnHorseLinkChild_Destroy,
    (ActorFunc)EnHorseLinkChild_Update,
    (ActorFunc)EnHorseLinkChild_Draw,
};

GLOBAL_ASM("binary/EnHorseLinkChild_Init.o")

GLOBAL_ASM("binary/EnHorseLinkChild_Destroy.o")

GLOBAL_ASM("binary/EnHorseLinkChild_Update.o")

GLOBAL_ASM("binary/EnHorseLinkChild_Draw.o")
}
