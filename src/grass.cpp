#include "grass.h"

#include <SFML/Graphics.hpp>

#include "resource_holder.h"

Grass::Grass() : Platform(&TextureHolder::getInstance()->get(Textures::GRASS), PLATFORM_TYPE::GRASS, -10) {
    initialize();
}

Grass::~Grass() {
}
