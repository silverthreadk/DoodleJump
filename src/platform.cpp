#include "platform.h"

#include <SFML/Graphics.hpp>

#include "player.h"
#include "config.h"

Platform* Platform::top_platform_;

Platform::Platform(sf::Texture* texture, PLATFORM_TYPE type, const int velocity) : Observer(texture),
    type_(type),
    velocity_(velocity) {
    initialize();
}

Platform::~Platform() {
}

void Platform::initialize() {
    x_ = rand() % kScreenWidth;

    if (!top_platform_) {
        y_ = rand() % 100 + kScreenHeight - 100;
    } else {
        y_ = top_platform_->getTop() - rand() % 100;
    }
    if(type_ == GRASS) top_platform_ = this;
}

void Platform::update(Player* player) {
    y_ = y_ - player->getVelocity();
    if (y_ > kScreenHeight) {
        y_ = std::min(-getHeight(), top_platform_->getTop() - rand() % 100 - player->getScore() / 100);
        x_ = rand() % kScreenWidth;
        if (type_ == GRASS) top_platform_ = this;
    }
}

void Platform::fallen(Player* player) {
    if ((player->getVelocity() > 0)
        && isIntersecting(player)) {
        player->jump(velocity_);
    }
}
