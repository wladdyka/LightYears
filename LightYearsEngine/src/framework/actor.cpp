#include "framework/actor.h"
#include "framework/core.h"

namespace ly {
    Actor::Actor(World *owningWorld, const std::string &texturePath)
        : mOwningWorld{owningWorld},
        mBeganPlay{false},
        mSprite{},
        mTexture{}
    {
        SetTexture(texturePath);
    }

    Actor::~Actor() {
        LOG("Actor destroyed");
    }

    void Actor::TickInternal(float deltaTime) {
        if (IsPendingDestroy()) {
            return;
        }

        Tick(deltaTime);
    }

    void Actor::BeingPlayInternal() {
        if (mBeganPlay) {
            return;
        }

        mBeganPlay = true;
        BeingPlay();
    }

    void Actor::BeingPlay() {
        LOG("Actor began play");
    }

    void Actor::Tick(float deltaTime) {
        LOG("Actor tick");
    }

    void Actor::SetTexture(const std::string &texturePath) {
        mTexture.loadFromFile(texturePath);
        mSprite.setTexture(mTexture);

        int textureWidth = mTexture.getSize().x;
        int textureHeight = mTexture.getSize().y;

        mSprite.setTextureRect(sf::IntRect{sf::Vector2i{}, sf::Vector2i{textureWidth, textureHeight}});
    }

    void Actor::Render(sf::RenderWindow &window) {
        if (IsPendingDestroy()) {
            return;
        }

        window.draw(mSprite);
    }
}
