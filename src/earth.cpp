#include "earth.h"

#include <SFML/Graphics.hpp>

#include "config.h"
#include "resource_holder.h"
#include "player.h"

std::shared_ptr<Platform> Earth::create() {
    std::shared_ptr<Platform> platform(new Earth);
    platform->initialize();
    return platform;
}

Earth::Earth() : Platform(&TextureHolder::getInstance()->get(Textures::EARTH), PLATFORM_TYPE::EARTH, 0) {
}

Earth::~Earth() {
}

void Earth::update(Player* player) {
    y_ = y_ - player->getVelocity();
    if (y_ > kScreenHeight) {
        y_ = std::min(-getHeight(), - rand() % kScreenHeight);
        x_ = rand() % getMaxX();
        sprite_->setColor(sf::Color::White);
    }
}

void Earth::fallen(Player* player) {
    if ((player->getVelocity() > 0)
        && isIntersecting(player)) {
        sprite_->setColor(sf::Color::Transparent);
    }
}
