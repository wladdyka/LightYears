#pragma once
#include "framework/core.h"

namespace ly {
    class Application;
    class Actor;

    class World {
    public:
        World(Application* owningApp);

        void BeginPlayInternal();
        void TickInternal(float deltaTime);

        virtual ~World();

        template<typename ActorType>
        weak<ActorType> SpawnActor();
    private:
        void BeginPlay();
        void Tick(float deltaTime);
        Application* mOwningApp;
        bool mBeganPlay;

        List<shared<Actor>> mActors;
        List<shared<Actor>> mPendingActors;
    };

    template<typename ActorType>
    weak<ActorType> World::SpawnActor() {
        shared<ActorType> spawnedActor{new ActorType{this}};
        mPendingActors.push_back(spawnedActor);
        return spawnedActor;
    }
}
