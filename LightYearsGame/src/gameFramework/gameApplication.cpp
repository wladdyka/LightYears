#include "gameFramework/gameApplication.h"
#include "framework/world.h"
#include "framework/actor.h"

ly::Application* GetApplication() {
    return new ly::GameApplication{};
}

namespace ly {
    GameApplication::GameApplication() {
        weak<World> newWorld = LoadWorld<World>();
        newWorld.lock()->SpawnActor<Actor>();
    }
}
