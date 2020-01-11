#include "coin.h"

#include <SFML/Graphics.hpp>

#include "player.h"
#include "config.h"
#include "resource_holder.h"

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
    y_ = y_ - player->getVelocity();
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
