#pragma once
#include "framework/object.h"

namespace ly {
    class World;

    class Actor : public Object {
    public:
        Actor(World* owningWorld);
        virtual ~Actor();

        void BeingPlayInternal();
        virtual void BeingPlay();
        virtual void Tick(float deltaTime);
    private:
        World* mOwningWorld;
        bool mBeganPlay;
    };
}