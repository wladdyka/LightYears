#pragma once
#include <SFML/Graphics.hpp>

namespace ly {
    class Application {
    public:
        Application();
        void Run();
    private:
        void RenderInternal();
        virtual void Render();

        void TickInternal(float deltaTime);
        virtual void Tick(float deltaTime);

        sf::RenderWindow mWindow;
        float mTargetFramerate;
        sf::Clock mTickClock;
    };
}