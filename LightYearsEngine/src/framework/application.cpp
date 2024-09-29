#include "framework/application.h"
#include "framework/core.h"
#include "framework/world.h"

namespace ly {
    Application::Application()
        : mWindow{sf::VideoMode(768, 1024), "LightYears"},
        mTargetFramerate{60.0f},
        mTickClock{},
        mCurrentWorld{}
    {
    }

    void Application::Run() {
        mTickClock.restart();
        float accumulatedTime{0.0f};
        float targetDeltaTime = 1.f / mTargetFramerate;

        while (mWindow.isOpen()) {
            sf::Event windowEvent{};
            while(mWindow.pollEvent(windowEvent)) {
                if (windowEvent.type == sf::Event::Closed) {
                    mWindow.close();
                }
            }

            float frameDeltaTime = mTickClock.restart().asSeconds();
            accumulatedTime += frameDeltaTime;
            while (accumulatedTime > targetDeltaTime) {
                accumulatedTime -= targetDeltaTime;
                TickInternal(targetDeltaTime);
            }

            RenderInternal();
        }
    }

    void Application::TickInternal(float deltaTime) {
        Tick(deltaTime);

        if (mCurrentWorld) {
            mCurrentWorld->TickInternal(deltaTime);
        }
    }

    void Application::Tick(float deltaTime) {

    }

    void Application::RenderInternal() {
        mWindow.clear();

        Render();

        mWindow.display();
    }

    void Application::Render() {
        sf::RectangleShape rect{sf::Vector2f{100, 100}};
        rect.setFillColor(sf::Color::Green);
        rect.setOrigin(50, 50);
        rect.setPosition(mWindow.getSize().x / 2, mWindow.getSize().y / 2);
        mWindow.draw(rect);
    }
}
