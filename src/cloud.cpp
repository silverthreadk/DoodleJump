#include "cloud.h"

#include <SFML/Graphics.hpp>

#include "config.h"
#include "resource_holder.h"
#include "player.h"

std::shared_ptr<Cloud> Cloud::create() {
    std::shared_ptr<Cloud> cloud(new Cloud);
    cloud->initialize();
    return cloud;
}

Cloud::Cloud() : Platform(&TextureHolder::getInstance()->get(Textures::CLOUD), -10) {
}

Cloud::~Cloud() {
}

void Cloud::fallen(Player* player) {
    if ((player->getVelocity() > 0)
        && isOverlappedToBottom(player)
        && !isHidden()) {
        player->jump(velocity_);
        setHidden(true);
    }
}
