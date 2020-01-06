#include "cloud.h"

#include <SFML/Graphics.hpp>

#include "config.h"
#include "resource_holder.h"
#include "player.h"

std::shared_ptr<Platform> Cloud::create() {
    std::shared_ptr<Platform> platform(new Cloud);
    platform->initialize();
    return platform;
}

Cloud::Cloud() : Platform(&TextureHolder::getInstance()->get(Textures::CLOUD), PLATFORM_TYPE::CLOUD, -10) {
}

Cloud::~Cloud() {
}

void Cloud::fallen(Player* player) {
    if ((player->getVelocity() > 0)
        && isIntersecting(player)
        && !isHidden()) {
        player->jump(velocity_);
        setHidden(true);
    }
}
