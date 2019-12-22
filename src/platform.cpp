#include "platform.h"

#include <SFML/Graphics.hpp>

#include "player.h"
#include "config.h"

Platform::Platform(sf::Texture* texture, PLATFORM_TYPE type, const int velocity) : Observer(texture),
    type_(type),
    velocity_(velocity) {
    initialize();
}

Platform::~Platform() {
}

void Platform::initialize() {
    x_ = rand() % (kScreenWidth - getWidth());
    y_ = rand() % kScreenHeight;
}

void Platform::update(Player* player) {
    y_ = y_ - player->getVelocity();
    if (y_ > kScreenHeight) {
        y_ = std::min(-getHeight(), -rand() % kScreenHeight);
        x_ = rand() % (kScreenWidth - getWidth());
    }
}

void Platform::fallen(Player* player) {
    if ((player->getVelocity() > 0)
        && isIntersecting(player)) {
        player->jump(velocity_);
    }
}
