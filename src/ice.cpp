#include "ice.h"

#include <SFML/Graphics.hpp>

#include "resource_holder.h"
#include "player.h"

std::shared_ptr<Platform> Ice::create() {
    std::shared_ptr<Platform> platform(new Ice);
    platform->initialize();
    return platform;
}

Ice::Ice() : Platform(&TextureHolder::getInstance()->get(Textures::ICE), -10), direction(1) {
}

Ice::~Ice() {
}

void Ice::move(Player* player) {
    if (x_ < 0) {
        direction = 1;
    } else if (x_ > getMaxX()) {
        direction = -1;
    }
    x_ += (3 * direction);
}
