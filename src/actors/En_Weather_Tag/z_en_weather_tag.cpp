extern "C" {
#include "z_en_weather_tag.hpp"

#define FLAGS 0x80000010

void EnWeatherTag_Init(Actor* actor, GameState* state);
void EnWeatherTag_Destroy(Actor* actor, GameState* state);
void EnWeatherTag_Update(Actor* actor, GameState* state);

GLOBAL_ASM("binary/z_En_Weather_Tag.data.o")

/*
ActorInit En_Weather_Tag_InitVars = {
    ACTOR_EN_WEATHER_TAG,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(EnWeatherTag),
    (ActorFunc)EnWeatherTag_Init,
    (ActorFunc)EnWeatherTag_Destroy,
    (ActorFunc)EnWeatherTag_Update,
    NULL,
};
*/

GLOBAL_ASM("binary/EnWeatherTag_Init.o")

GLOBAL_ASM("binary/EnWeatherTag_Destroy.o")

GLOBAL_ASM("binary/EnWeatherTag_Update.o")
}
