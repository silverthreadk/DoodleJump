#include "player.h"

#include <SFML/Graphics.hpp>

#include "game.h"
#include "resource_holder.h"
#include "config.h"

Player::Player(Game& game) : Entity(&TextureHolder::getInstance()->get(Textures::DOODLE)), game_(game) {
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
    x_ = (kScreenWidth - getWidth()) / 2;
    y_ = kJumpHeight;
    horizontal_padding_ = 20;
    velocity_ = 0;
    dy_ = 0;
    lives_ = 3;
    score_ = 0;
}

void Player::moveToLeft() {
    x_ -= 3;
    x_ = std::max(x_, 0);
}

void Player::moveToRight() {
    x_ += 3;
    x_ = std::min(x_, kScreenWidth - getWidth());
}

void Player::drop() {
    velocity_ += 0.2;
    y_ += velocity_;
}

void Player::jump(const int velocity) {
    dy_ = kScreenHeight - y_;
    velocity_ = velocity;
}

void Player::revive() {
    --lives_;
    if (lives_ < 1) {
        game_.gameOver();
        return;
    }

    x_ = (kScreenWidth - getWidth()) / 2;
    y_ = kJumpHeight;
    velocity_ = 0;
    dy_ = 0;
}

bool Player::isLowestPoint() const {
    return y_ > kScreenHeight;
}

bool Player::isHighestPoint() {
    if (y_ < kJumpHeight) {
        y_ = kJumpHeight;
        return true;
    }
    return false;
}

void Player::addScore() {
    if (dy_ < 100) return;

    score_ += 10;
    dy_ -= 100;
}
