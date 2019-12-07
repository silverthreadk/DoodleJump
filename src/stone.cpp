#include "stone.h"

#include <SFML/Graphics.hpp>

#include "resource_holder.h"

Stone::Stone() : Platform(&TextureHolder::getInstance()->get(Textures::STONE), PLATFORM_TYPE::STONE, -5) {
    initialize();
}

Stone::~Stone() {
}
