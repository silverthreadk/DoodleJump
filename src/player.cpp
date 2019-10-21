#include "player.h"

#include <SFML/Graphics.hpp>

Player::Player(sf::Texture* texture) : sprite_(new sf::Sprite(*texture)), jump_height(200) {
    initialize();
}

void Player::initialize() {
    x = 160;
    y = 0;
    dy = 0;
    score = 0;
}

void Player::moveToLeft() {
    x -= 3;
}

void Player::moveToRight() {
    x += 3;
}

bool Player::update() {
    dy += 0.2;
    y += dy;

    return (y > 500);
}

void Player::jump() {
    dy = -10;
}

bool Player::isHighestPoint() {
    if (y < jump_height) {
        y = jump_height;
        return true;
    }
    return false;
}

void Player::addScore() {
    score += 10;
}

void Player::draw(sf::RenderWindow* app) {
    sprite_->setPosition(x, y);
    app->draw(*sprite_);
}