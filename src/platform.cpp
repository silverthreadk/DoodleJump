#include "platform.h"

#include <SFML/Graphics.hpp>

#include "player.h"
#include "config.h"

Platform::Platform(sf::Texture* texture, PLATFORM_TYPE type, const int velocity) : Observer(texture),
    type_(type),
    velocity_(velocity) {
}

Platform::~Platform() {
}

void Platform::initialize() {
    x_ = rand() % getMaxX();
    y_ = rand() % getMaxY();
}

void Platform::update(Player* player) {
    y_ = y_ - player->getVelocity();
    if (y_ > kScreenHeight) {
        y_ = std::min(-getHeight(), -rand() % kScreenHeight);
        x_ = rand() % getMaxX();
        setHidden(false);
    }
}

void Platform::fallen(Player* player) {
    if ((player->getVelocity() > 0)
        && isOverlappedToBottom(player)) {
        player->jump(velocity_);
    }
}
