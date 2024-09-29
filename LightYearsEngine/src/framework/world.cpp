#include "framework/world.h"
#include "framework/core.h"

namespace ly {
    World::World(Application *owningApp)
        : mOwningApp{owningApp},
        mBeganPlay{false}
    {

    }

    void World::BeginPlayInternal() {
        if (mBeganPlay) {
            return;
        }

        mBeganPlay = true;
        BeginPlay();
    }

    void World::TickInternal(float deltaTime) {
        Tick(deltaTime);
    }

    World::~World() {
    }

    void World::BeginPlay() {
        LOG("began play");
    }

    void World::Tick(float deltaTime) {
        LOG("tick at framerate %f", 1.f/deltaTime);
    }
}
