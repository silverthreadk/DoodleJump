#include "entity.h"

#include <SFML/Graphics.hpp>

Entity::Entity(sf::Texture* texture) : sprite_(new sf::Sprite(*texture)),
    x_(0),
    y_(0),
    horizontal_padding_(0) {
}

Entity::Entity(sf::Texture* texture, const int x, const int y) : sprite_(new sf::Sprite(*texture)),
    x_(x),
    y_(y),
    horizontal_padding_(0) {
}

Entity::~Entity() {
    delete sprite_;
}

void Entity::draw(sf::RenderWindow* app) {
    sprite_->setPosition(x_, y_);
    app->draw(*sprite_);
}

bool Entity::isIntersecting(Entity* entity) const {
    return (entity->getRight() - entity->horizontal_padding_ > getLeft())
        && (entity->getLeft() + entity->horizontal_padding_ < getRight())
        && (entity->getBottom() > getTop())
        && (entity->getBottom() < getBottom());
}

int Entity::getRight() const {
    return x_ + sprite_->getLocalBounds().width;
}

int Entity::getBottom() const {
    return y_ + getHeight();
}

int Entity::getHeight() const {
    return sprite_->getLocalBounds().height;
}
