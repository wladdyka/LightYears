#include "gameFramework/gameApplication.h"
#include "framework/world.h"
#include "framework/actor.h"

ly::Application* GetApplication() {
    return new ly::GameApplication{};
}

namespace ly {
    GameApplication::GameApplication()
        : Application{600, 980, "Light Years", sf::Style::Titlebar | sf::Style::Close}
    {
        weak<World> newWorld = LoadWorld<World>();
        weak<Actor> newActor = newWorld.lock()->SpawnActor<Actor>();
        newActor.lock()->SetTexture("C:/Users/wladdyka/Projects/LightYears/LightYearsGame/assets/SpaceShooterRedux/PNG/playerShip1_blue.png");
    }
}
