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
    x_ = 160;
    y_ = jump_height_;
    horizontal_padding_ = 20;
    velocity_ = 0;
    dy_ = 0;
    lives_ = 3;
    score_ = 0;
}

void Player::moveToLeft() {
    x_ -= 3;
}

void Player::moveToRight() {
    x_ += 3;
}

void Player::drop() {
    velocity_ += 0.2;
    y_ += velocity_;
}

void Player::jump(const int velocity) {
    dy_ = 500 - y_;
    velocity_ = velocity;
}

void Player::revive() {
    --lives_;
    if (lives_ < 1) {
        game_.gameOver();
        return;
    }

    x_ = 160;
    y_ = 200;
    velocity_ = 0;
    dy_ = 0;
}

bool Player::isLowestPoint() const {
    return y_ > 500;
}

bool Player::isHighestPoint() {
    if (y_ < jump_height_) {
        y_ = jump_height_;
        return true;
    }
    return false;
}

void Player::addScore() {
    if (dy_ < 100) return;

    score_ += 10;
    dy_ -= 100;
}
