extern "C" {
#include "z_en_ssh.hpp"

#define FLAGS 0x00000035

void EnSsh_Init(Actor* actor, GameState* state);
void EnSsh_Destroy(Actor* actor, GameState* state);
void EnSsh_Update(Actor* actor, GameState* state);
void EnSsh_Draw(Actor* actor, GameState* state);

GLOBAL_ASM("binary/z_En_Ssh.data.o")

ActorInit En_Ssh_InitVars = {
    ACTOR_EN_SSH,
    ACTORCAT_NPC,
    FLAGS,
    OBJECT_SSH,
    sizeof(EnSsh),
    (ActorFunc)EnSsh_Init,
    (ActorFunc)EnSsh_Destroy,
    (ActorFunc)EnSsh_Update,
    (ActorFunc)EnSsh_Draw,
};

GLOBAL_ASM("binary/EnSsh_Init.o")

GLOBAL_ASM("binary/EnSsh_Destroy.o")

GLOBAL_ASM("binary/EnSsh_Update.o")

GLOBAL_ASM("binary/EnSsh_Draw.o")
}
