#include "entity/life.h"

#include <SFML/Graphics.hpp>

Life::Life(sf::Texture* texture, const int x, const int y) : Entity(texture, x, y) {
    sprite_->setScale(0.5f, 0.5f);
}

Life::~Life() {
}
