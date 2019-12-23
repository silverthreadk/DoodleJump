#include "ice.h"

#include <SFML/Graphics.hpp>

#include "config.h"
#include "resource_holder.h"
#include "player.h"

Ice::Ice() : Platform(&TextureHolder::getInstance()->get(Textures::ICE), PLATFORM_TYPE::ICE, -10), direction(1) {
    initialize();
}

Ice::~Ice() {
}

void Ice::move(Player* player) {
    if (x_ < 0) {
        direction = 1;
    } else if (x_ > (kScreenWidth - getWidth())) {
        direction = -1;
    }
    x_ += (3 * direction);
}