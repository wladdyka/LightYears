#include <iostream>
#include <SFML/Graphics.hpp>
#include "framework/application.h"

int main() {
    auto app = std::make_unique<ly::Application>();
    app->Run();

    return 0;
}
