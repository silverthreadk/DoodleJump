#include "grass.h"

#include <SFML/Graphics.hpp>

#include "config.h"
#include "resource_holder.h"
#include "player.h"

Grass* Grass::top_;

Grass::Grass() : Platform(&TextureHolder::getInstance()->get(Textures::GRASS), PLATFORM_TYPE::GRASS, -10) {
    initialize();
}

Grass::~Grass() {
}

void Grass::initialize() {
    x_ = rand() % (kScreenWidth - getWidth());

    if (!top_) {
        y_ = rand() % 100 + kScreenHeight - 100;
    } else {
        y_ = top_->getTop() - rand() % 100;
    }
    top_ = this;
}

void Grass::update(Player* player) {
    y_ = y_ - player->getVelocity();
    if (y_ > kScreenHeight) {
        y_ = std::min(-getHeight(), top_->getTop() - rand() % 100 - player->getScore() / 100);
        x_ = rand() % (kScreenWidth - getWidth());
        top_ = this;
    }
}
