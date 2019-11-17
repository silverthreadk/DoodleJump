#include "platform.h"

#include <SFML/Graphics.hpp>

#include "player.h"

Platform::Platform(sf::Texture* texture) : Observer(texture) {
    initialize();
}

Platform::~Platform() {
}

void Platform::initialize() {
    x_ = rand() % 400;
    y_ = rand() % 533;
}

void Platform::update(Player* player) {
    y_ = y_ - player->getVelocity();
    if (y_ > 533) {
        y_ = -rand() % 250;
        x_ = rand() % 400;
    }
}

void Platform::fallen(Player* player) {
    if ((player->getVelocity() > 0)
        && isIntersecting(player)) {
        player->jump();
    }
}
