#include "plat.h"

#include <SFML/Graphics.hpp>

Plat::Plat() {
    initialize();
}

void Plat::initialize() {
    x = rand() % 400;
    y = rand() % 533;
}

void Plat::update(int dy, int* score) {
    y = y - dy;
    if (y > 533) { 
        y = -rand() % 250;
        x = rand() % 400;
        *score += 10;
    }
}

void Plat::calculate(int player_x, int player_y, float* dy) {
    if ((player_x + 50 > x) && (player_x + 20 < x + 68)
        && (player_y + 70 > y) && (player_y + 70 < y + 14) && (*dy > 0)) *dy = -10;
}

void Plat::draw(sf::RenderWindow* app, sf::Sprite* sprite) {
    sprite->setPosition(x, y);
    app->draw(*sprite);
}
