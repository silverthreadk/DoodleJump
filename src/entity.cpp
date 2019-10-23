#include "entity.h"

#include <SFML/Graphics.hpp>

Entity::Entity(sf::Texture* texture) : sprite_(new sf::Sprite(*texture)) {
}

Entity::~Entity() {
    delete sprite_;
}

void Entity::draw(sf::RenderWindow* app) {
    sprite_->setPosition(x, y);
    app->draw(*sprite_);
}
