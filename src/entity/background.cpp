#include "entity/background.h"

#include <SFML/Graphics.hpp>

#include "resource_holder.h"

Background::Background() : Entity(&TextureHolder::getInstance()->get(Textures::BACKGROUND)) {
}

Background::~Background() {
}