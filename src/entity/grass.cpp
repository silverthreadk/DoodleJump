#include "entity/grass.h"

#include <SFML/Graphics.hpp>

#include "config.h"
#include "resource_holder.h"
#include "entity/player.h"

int Grass::top_ = kScreenHeight;

std::unique_ptr<Grass> Grass::create() {
    std::unique_ptr<Grass> grass(new Grass);
    grass->initialize();
    return grass;
}

Grass::Grass() : Platform(&TextureHolder::getInstance()->get(Textures::GRASS), -10) {
}

Grass::~Grass() {
}

void Grass::initialize() {
    x_ = rand() % getMaxX();
    y_ = top_ - rand() % 50 - 50;
    top_ = y_;
}

void Grass::update(Player* player) {
    y_ -= player->getVelocity();
    if (y_ > kScreenHeight) {
        x_ = rand() % getMaxX();
        y_ = top_ - std::min(kJumpHeight, rand() % 30 + (player->getScore() / 1000) * 10);
        top_ = y_;
    }
}
