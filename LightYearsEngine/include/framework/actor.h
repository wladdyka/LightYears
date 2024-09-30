#pragma once

namespace ly {
    class World;

    class Actor {
    public:
        Actor(World* owningWorld);
        void BeingPlayInternal();
        virtual void BeingPlay();
        virtual void Tick(float deltaTime);
    private:
        World* mOwningWorld;
        bool mBeganPlay;
    };
}