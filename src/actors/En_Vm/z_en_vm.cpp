extern "C" {
#include "z_en_vm.hpp"

#define FLAGS 0x00000011

void EnVm_Init(Actor* actor, GameState* state);
void EnVm_Destroy(Actor* actor, GameState* state);
void EnVm_Update(Actor* actor, GameState* state);
void EnVm_Draw(Actor* actor, GameState* state);

GLOBAL_ASM("binary/z_En_Vm.data.o")

ActorInit En_Vm_InitVars = {
    ACTOR_EN_VM,
    ACTORCAT_ENEMY,
    FLAGS,
    OBJECT_VM,
    sizeof(EnVm),
    (ActorFunc)EnVm_Init,
    (ActorFunc)EnVm_Destroy,
    (ActorFunc)EnVm_Update,
    (ActorFunc)EnVm_Draw,
};

GLOBAL_ASM("binary/EnVm_Init.o")

GLOBAL_ASM("binary/EnVm_Destroy.o")

GLOBAL_ASM("binary/EnVm_Update.o")

GLOBAL_ASM("binary/EnVm_Draw.o")
}
