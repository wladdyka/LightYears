#include "framework/actor.h"
#include "framework/core.h"

namespace ly {
    Actor::Actor(World *owningWorld)
        : mOwningWorld{owningWorld},
        mBeganPlay{false}
    { }

    Actor::~Actor() {
        LOG("Actor destroyed");
    }

    void Actor::BeingPlayInternal() {
        if (mBeganPlay) {
            return;
        }

        mBeganPlay = true;
        BeingPlay();
    }

    void Actor::BeingPlay() {
        LOG("Actor began play");
    }

    void Actor::Tick(float deltaTime) {
        LOG("Actor tick");
    }
}
