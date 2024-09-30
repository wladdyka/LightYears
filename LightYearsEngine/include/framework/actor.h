#pragma once
#include "framework/object.h"
#include "framework/core.h"
#include <SFML/Graphics.hpp>

namespace ly {
    class World;

    class Actor : public Object {
    public:
        Actor(World* owningWorld, const std::string& texturePath = "");
        virtual ~Actor();

        void TickInternal(float deltaTime);
        void BeingPlayInternal();
        virtual void BeingPlay();
        virtual void Tick(float deltaTime);
        void SetTexture(const std::string& texturePath);
        void Render(sf::RenderWindow& window);
    private:
        World* mOwningWorld;
        bool mBeganPlay;

        sf::Sprite mSprite;
        sf::Texture mTexture;
    };
}