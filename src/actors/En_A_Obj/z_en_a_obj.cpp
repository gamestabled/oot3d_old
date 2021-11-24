extern "C" {
#include "z_en_a_obj.hpp"

#define FLAGS 0x00000010

void EnAObj_Init(Actor* actor, GameState* state);
void EnAObj_Destroy(Actor* actor, GameState* state);
void EnAObj_Update(Actor* actor, GameState* state);
void EnAObj_Draw(Actor* actor, GameState* state);

/*
ActorInit En_A_Obj_InitVars = {
    ACTOR_EN_A_OBJ,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(EnAObj),
    (ActorFunc)EnAObj_Init,
    (ActorFunc)EnAObj_Destroy,
    (ActorFunc)EnAObj_Update,
    (ActorFunc)EnAObj_Draw,
};
*/

GLOBAL_ASM("binary/EnAObj_Init.o")

GLOBAL_ASM("binary/EnAObj_Destroy.o")

GLOBAL_ASM("binary/EnAObj_Update.o")

GLOBAL_ASM("binary/EnAObj_Draw.o")
}
