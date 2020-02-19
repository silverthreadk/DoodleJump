#include "stone.h"

#include <SFML/Graphics.hpp>

#include "resource_holder.h"

std::shared_ptr<Stone> Stone::create() {
    std::shared_ptr<Stone> stone(new Stone);
    stone->initialize();
    return stone;
}

Stone::Stone() : Platform(&TextureHolder::getInstance()->get(Textures::STONE), -5) {
}

Stone::~Stone() {
}
