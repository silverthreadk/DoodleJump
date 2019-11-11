#include "player.h"

#include <SFML/Graphics.hpp>

#include "game.h"

Player::Player(Game& game, sf::Texture* texture) : Entity(texture), game_(game), jump_height_(200) {
    initialize();
}

Player::~Player() {
}

void Player::restart() {
    if (game_.isPlaying()) return;

    game_.initialize();
    initialize();
}

void Player::initialize() {
    x = 160;
    y = 0;
    velocity_ = 0;
    dy_ = 0;
    score = 0;
}

void Player::moveToLeft() {
    x -= 3;
}

void Player::moveToRight() {
    x += 3;
}

void Player::drop() {
    velocity_ += 0.2;
    y += velocity_;
}

void Player::jump() {
    dy_ = 500 - y;
    velocity_ = -10;
}

bool Player::isLowestPoint() {
    return y > 500;
}

bool Player::isHighestPoint() {
    if (y < jump_height_) {
        y = jump_height_;
        return true;
    }
    return false;
}

void Player::addScore() {
    if (dy_ < 100) return;

    score += 10;
    dy_ -= 100;
}
