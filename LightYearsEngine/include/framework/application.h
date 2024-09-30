#pragma once
#include <SFML/Graphics.hpp>

#include "world.h"
#include "framework/core.h"

namespace ly {
    class World;

    class Application {
    public:
        Application(unsigned int width, unsigned int height, const std::string& title, sf::Uint32 style);
        void Run();

        template<typename WorldType>
        weak<WorldType> LoadWorld();
    private:
        void RenderInternal();
        virtual void Render();

        void TickInternal(float deltaTime);
        virtual void Tick(float deltaTime);

        sf::RenderWindow mWindow;
        float mTargetFramerate;
        sf::Clock mTickClock;
        shared<World> mCurrentWorld;
    };

    template<typename WorldType>
    weak<WorldType> Application::LoadWorld() {
        shared<WorldType> newWorld{new WorldType{this}};
        mCurrentWorld = newWorld;
        mCurrentWorld->BeginPlayInternal();
        return newWorld;
    }

}