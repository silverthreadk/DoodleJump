#include "resource_manager.h"

#include <SFML/Graphics.hpp>

#include "resource_holder.h"
#include "config.h"

ResourceManager::ResourceManager() {
    loadResource();
}

ResourceManager::~ResourceManager() {
}

void ResourceManager::loadResource() {
    TextureHolder* texture_holder = TextureHolder::getInstance();
    texture_holder->load(Textures::BACKGROUND, RESOURCE_PATH + "images/background.png");
    texture_holder->load(Textures::GRASS, RESOURCE_PATH + "images/grass.png");
    texture_holder->load(Textures::STONE, RESOURCE_PATH + "images/stone.png");
    texture_holder->load(Textures::CLOUD, RESOURCE_PATH + "images/cloud.png");
    texture_holder->load(Textures::EARTH, RESOURCE_PATH + "images/earth.png");
    texture_holder->load(Textures::ICE, RESOURCE_PATH + "images/ice.png");
    texture_holder->load(Textures::COIN, RESOURCE_PATH + "images/coin.png");
    texture_holder->load(Textures::DOODLE, RESOURCE_PATH + "images/doodle.png");

    FontHolder* font_holder = FontHolder::getInstance();
    font_holder->load(Fonts::MAIN, RESOURCE_PATH + "fonts/nanumgothic.ttf");
}
