#include "earth.h"

#include <SFML/Graphics.hpp>

#include "resource_holder.h"

Earth::Earth() : Platform(&TextureHolder::getInstance()->get(Textures::EARTH), PLATFORM_TYPE::EARTH, -5) {
    initialize();
}

Earth::~Earth() {
}
