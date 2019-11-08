#include "player.h"

#include <SFML/Graphics.hpp>

#include "game.h"

Player::Player(Game& game, sf::Texture* texture) : Entity(texture), game_(game), jump_height(200) {
    initialize();
}

Player::~Player() {
}

void Player::initialize() {
    if (game_.isPlaying()) return;
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

void Player::drop() {
    dy += 0.2;
    y += dy;
}

void Player::jump() {
    dy = -10;
}

bool Player::isLowestPoint() {
    return y > 500;
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
