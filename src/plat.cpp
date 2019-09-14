#include "plat.h"

#include <SFML/Graphics.hpp>

#include "player.h"

Plat::Plat() {
    initialize();
}

void Plat::initialize() {
    x = rand() % 400;
    y = rand() % 533;
}

void Plat::update(Player* player) {
    y = y - player->getVelocity();
    if (y > 533) { 
        y = -rand() % 250;
        x = rand() % 400;
        player->addScore();
    }
}

void Plat::calculate(Player* player) {
    if ((player->getX() + 50 > x) && (player->getX() + 20 < x + 68)
        && (player->getY() + 70 > y) && (player->getY() + 70 < y + 14) && (player->getVelocity() > 0)) player->jump();
}

void Plat::draw(sf::RenderWindow* app, sf::Sprite* sprite) {
    sprite->setPosition(x, y);
    app->draw(*sprite);
}
