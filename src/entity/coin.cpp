#include "entity/coin.h"

#include <SFML/Graphics.hpp>

#include "config.h"
#include "resource_holder.h"
#include "entity/player.h"

std::unique_ptr<Coin> Coin::create() {
    std::unique_ptr<Coin> coin(new Coin);
    coin->initialize();
    return coin;
}

Coin::Coin() : Observer(&TextureHolder::getInstance()->get(Textures::COIN)) {
    initialize();
}

Coin::~Coin() {
}

void Coin::initialize() {
    x_ = rand() % getMaxX();
    y_ = rand() % getMaxY();
}

void Coin::update(Player* player) {
    y_ -= player->getVelocity();
    if (y_ > kScreenHeight) {
        y_ = std::min(-getHeight(), -rand() % kScreenHeight);
        x_ = rand() % getMaxX();
        setHidden(false);
    }
}

void Coin::fallen(Player* player) {
    if (!isHidden() && isOverlapped(player)) {
        player->earnCoin();
        setHidden(true);
    }
}
