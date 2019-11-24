#include "platform.h"

#include <SFML/Graphics.hpp>

#include "player.h"

Platform* Platform::top_platform_;

Platform::Platform(sf::Texture* texture) : Observer(texture) {
    initialize();
}

Platform::~Platform() {
}

void Platform::initialize() {
    x_ = rand() % 400;

    if (!top_platform_) {
        y_ = rand() % 200 + 333;
    } else {
        y_ = top_platform_->getTop() - rand() % 100;
    }
    top_platform_ = this;
}

void Platform::update(Player* player) {
    y_ = y_ - player->getVelocity();
    if (y_ > 533) {
        y_ = std::min(-getHeight(), top_platform_->getTop() - rand() % 100 - player->getScore() / 100);
        x_ = rand() % 400;
        top_platform_ = this;
    }
}

void Platform::fallen(Player* player) {
    if ((player->getVelocity() > 0)
        && isIntersecting(player)) {
        player->jump();
    }
}
