#include "actor.hpp"

__attribute__((section("Actor_Kill")))
void Actor_Kill(Actor* actor) {
    actor->draw = 0;
    actor->update = 0;
    actor->flags &= ~0x1;
}

