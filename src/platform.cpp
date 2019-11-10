#include "platform.h"

#include <SFML/Graphics.hpp>

#include "player.h"

Platform::Platform(sf::Texture* texture) : Observer(texture) {
    initialize();
}

Platform::~Platform() {
}

void Platform::initialize() {
    x = rand() % 400;
    y = rand() % 533;
}

void Platform::update(Player* player) {
    y = y - player->getVelocity();
    if (y > 533) {
        y = -rand() % 250;
        x = rand() % 400;
    }
}

void Platform::calculate(Player* player) {
    if ((player->getX() + 50 > x) && (player->getX() + 20 < x + 68)
        && (player->getY() + 70 > y) && (player->getY() + 70 < y + 14) && (player->getVelocity() > 0)) player->jump();
}
