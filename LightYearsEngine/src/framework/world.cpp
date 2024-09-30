#include "framework/world.h"

#include "framework/actor.h"
#include "framework/core.h"

namespace ly {
    World::World(Application *owningApp)
        : mOwningApp{owningApp},
        mBeganPlay{false},
        mActors{},
        mPendingActors{}
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
        for(const shared<Actor>& actor : mPendingActors) {
            mActors.push_back(actor);
            actor->BeingPlayInternal();
        }
        mPendingActors.clear();

        for(auto iter = mActors.begin(); iter != mActors.end();) {
            if (iter->get()->IsPendingDestroy()) {
                iter = mActors.erase(iter);
            } else {
                iter->get()->TickInternal(deltaTime);
                ++iter;
            }
        }

        Tick(deltaTime);
    }

    void World::Render(sf::RenderWindow &window) {
        for(const auto& actor : mActors) {
            actor->Render(window);
        }
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
