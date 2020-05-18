#include "entity/ice.h"

#include <SFML/Graphics.hpp>

#include "resource_holder.h"
#include "entity/player.h"

std::unique_ptr<Ice> Ice::create() {
    std::unique_ptr<Ice> ice(new Ice);
    ice->initialize();
    return ice;
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
