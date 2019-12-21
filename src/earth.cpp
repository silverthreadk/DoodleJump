#include "earth.h"

#include <SFML/Graphics.hpp>

#include "config.h"
#include "resource_holder.h"
#include "player.h"

Earth::Earth() : Platform(&TextureHolder::getInstance()->get(Textures::EARTH), PLATFORM_TYPE::EARTH, 0) {
    initialize();
}

Earth::~Earth() {
}

void Earth::initialize() {
    x_ = rand() % (kScreenWidth - getWidth());
    y_ = rand() % 533;
}

void Earth::update(Player* player) {
    y_ = y_ - player->getVelocity();
    if (y_ > kScreenHeight) {
        y_ = std::min(-getHeight(), - rand() % 200);
        x_ = rand() % (kScreenWidth - getWidth());
        sprite_->setColor(sf::Color::White);
    }
}

void Earth::fallen(Player* player) {
    if ((player->getVelocity() > 0)
        && isIntersecting(player)) {
        sprite_->setColor(sf::Color::Transparent);
    }
}
