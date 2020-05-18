#include "entity/entity.h"

#include <SFML/Graphics.hpp>

#include "config.h"

Entity::Entity(sf::Texture* texture)
    : sprite_(new sf::Sprite(*texture)),
    x_(0),
    y_(0),
    horizontal_padding_(0) {
}

Entity::Entity(sf::Texture* texture, const int x, const int y)
    : sprite_(new sf::Sprite(*texture)),
    x_(x),
    y_(y),
    horizontal_padding_(0) {
}

Entity::Entity(sf::Texture* texture, const int x, const int y, const int horizontal_padding)
    : sprite_(new sf::Sprite(*texture)),
    x_(x),
    y_(y),
    horizontal_padding_(horizontal_padding) {
}

Entity::~Entity() {
    delete sprite_;
}

void Entity::draw(sf::RenderWindow* app) {
    sprite_->setPosition(x_, y_);
    app->draw(*sprite_);
}

void Entity::setHidden(const bool hidden) {
    if (hidden) sprite_->setColor(sf::Color::Transparent);
    else sprite_->setColor(sf::Color::White);
}

bool Entity::isHidden() const {
    return sprite_->getColor() == sf::Color::Transparent;
}

bool Entity::isOverlapped(Entity* entity) const {
    return (entity->getRight() - entity->horizontal_padding_ > getLeft())
        && (entity->getLeft() + entity->horizontal_padding_ < getRight())
        && (entity->getBottom() > getTop())
        && (entity->getTop() < getBottom());
}

bool Entity::isOverlappedToBottom(Entity* entity) const {
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

int Entity::getWidth() const {
    return sprite_->getLocalBounds().width;
}

int Entity::getHeight() const {
    return sprite_->getLocalBounds().height;
}

int Entity::getMaxX() const {
    return kScreenWidth - getWidth();
}

int Entity::getMaxY() const {
    return kScreenHeight - getHeight();
}
