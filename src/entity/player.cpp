#include "entity/player.h"

#include <SFML/Graphics.hpp>

#include "game.h"
#include "resource_holder.h"
#include "config.h"

Player::Player(Game& game)
    : Entity(&TextureHolder::getInstance()->get(Textures::DOODLE), 0, 0, 20),
    game_(game),
    velocity_(0),
    altitude_(0),
    coin_(0),
    lives_(kNumberOfLife),
    score_(0) {
    initialize();
}

Player::~Player() {
}

void Player::restart() {
    if (game_.isPlaying()) return;

    game_.initialize();
    initialize();
}

void Player::close() {
    game_.close();
}

void Player::moveToLeft() {
    x_ -= 3;
    x_ = std::max(x_, 0);
}

void Player::moveToRight() {
    x_ += 3;
    x_ = std::min(x_, getMaxX());
}

void Player::drop() {
    velocity_ += 0.2;
    y_ += velocity_;
    altitude_ += -velocity_;

    calculateScore();
}

void Player::jump(const int velocity) {
    velocity_ = velocity;
}

void Player::revive() {
    --lives_;
    if (lives_ < 1) {
        game_.gameOver();
        return;
    }

    initializeLocation();
    altitude_ += kScreenHeight - y_;
}

bool Player::isLowestPoint() const {
    return y_ > kScreenHeight;
}

bool Player::isHighestPoint() const {
    return y_ < kJumpHeight;
}

void Player::keepJumpHeight() {
    y_ = kJumpHeight;
}

void Player::earnCoin() {
    coin_ += 1;
}

void Player::initialize() {
    lives_ = kNumberOfLife;
    score_ = 0;
    altitude_ = 0;
    coin_ = 0;

    initializeLocation();
}

void Player::initializeLocation() {
    x_ = getMaxX() / 2;
    y_ = kJumpHeight;
    velocity_ = 0;
}

void Player::calculateScore() {
    score_ = std::max(score_, coin_ * 10 + altitude_ / 10);
}
