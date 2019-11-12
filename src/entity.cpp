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

bool Entity::isIntersecting(Entity* entity) const {
    return (entity->getRight() - entity->horizontal_padding > getLeft())
        && (entity->getLeft() + entity->horizontal_padding < getRight())
        && (entity->getBottom() > getTop())
        && (entity->getBottom() < getBottom());
}

int Entity::getRight() const {
    return x + sprite_->getLocalBounds().width;
}

int Entity::getBottom() const {
    return y + sprite_->getLocalBounds().height;
}
