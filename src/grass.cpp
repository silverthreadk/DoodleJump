#include "grass.h"

#include <SFML/Graphics.hpp>

#include "config.h"
#include "resource_holder.h"
#include "player.h"

int Grass::top_ = kScreenHeight;

std::shared_ptr<Platform> Grass::create() {
    std::shared_ptr<Platform> platform(new Grass);
    platform->initialize();
    return platform;
}

Grass::Grass() : Platform(&TextureHolder::getInstance()->get(Textures::GRASS), PLATFORM_TYPE::GRASS, -10) {
}

Grass::~Grass() {
}

void Grass::initialize() {
    x_ = rand() % getMaxX();
    y_ = top_ - rand() % 50 - 50;
    top_ = y_;
}

void Grass::update(Player* player) {
    y_ = y_ - player->getVelocity();
    if (y_ > kScreenHeight) {
        x_ = rand() % getMaxX();
        y_ = top_ - std::min(kJumpHeight, rand() % 30 + (player->getScore() / 1000) * 10);
        top_ = y_;
    }
}
