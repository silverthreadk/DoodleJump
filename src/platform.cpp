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

void Platform::fallen(Player* player) {
    if ((player->getVelocity() > 0)
        && isIntersecting(player)) {
        player->jump();
    }
}
