#include "framework/application.h"
#include "framework/core.h"
#include "framework/world.h"

namespace ly {
    Application::Application(unsigned int width, unsigned int height, const std::string &title, sf::Uint32 style)
    : mWindow{sf::VideoMode(width, height), title, style},
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
        if (mCurrentWorld) {
            mCurrentWorld->Render(mWindow);
        }
    }
}
