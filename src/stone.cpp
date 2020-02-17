#include "stone.h"

#include <SFML/Graphics.hpp>

#include "resource_holder.h"

std::shared_ptr<Platform> Stone::create() {
    std::shared_ptr<Platform> platform(new Stone);
    platform->initialize();
    return platform;
}

Stone::Stone() : Platform(&TextureHolder::getInstance()->get(Textures::STONE), -5) {
}

Stone::~Stone() {
}
