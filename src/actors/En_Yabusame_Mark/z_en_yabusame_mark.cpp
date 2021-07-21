extern "C" {
#include "z_en_yabusame_mark.hpp"

#define FLAGS 0x00000000

void EnYabusameMark_Init(Actor* actor, GameState* state);
void EnYabusameMark_Destroy(Actor* actor, GameState* state);
void EnYabusameMark_Update(Actor* actor, GameState* state);

/*
ActorInit En_Yabusame_Mark_InitVars = {
    ACTOR_EN_YABUSAME_MARK,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(EnYabusameMark),
    (ActorFunc)EnYabusameMark_Init,
    (ActorFunc)EnYabusameMark_Destroy,
    (ActorFunc)EnYabusameMark_Update,
    (ActorFunc)NULL,
};
*/
}
