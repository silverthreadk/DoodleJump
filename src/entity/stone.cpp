#include "entity/stone.h"

#include <SFML/Graphics.hpp>

#include "resource_holder.h"

std::unique_ptr<Stone> Stone::create() {
    std::unique_ptr<Stone> stone(new Stone);
    stone->initialize();
    return stone;
}

Stone::Stone() : Platform(&TextureHolder::getInstance()->get(Textures::STONE), -5) {
}

Stone::~Stone() {
}
