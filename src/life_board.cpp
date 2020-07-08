#include "life_board.h"

#include <SFML/Graphics.hpp>

#include "config.h"
#include "resource_holder.h"
#include "entity/life.h"


LifeBoard::LifeBoard() : life_index_(kNumberOfLife - 1) {
    int x = kScreenWidth, y = 10;
    sf::Texture& texture = TextureHolder::getInstance()->get(Textures::DOODLE);
    for (int i = 0; i < kNumberOfLife; ++i) {
        x -= texture.getSize().x / 2 - 5;
        lives_.push_back(std::unique_ptr<Life>(new Life(&texture, x, y)));
    }
}

LifeBoard::~LifeBoard() {
}

void LifeBoard::initialize() {
    life_index_ = kNumberOfLife - 1;
    for (auto& life : lives_) {
        life->setHidden(false);
    }
}

void LifeBoard::update() {
    if (life_index_ < 0) return;
    lives_[life_index_--]->setHidden(true);
}

void LifeBoard::draw(sf::RenderWindow* app) {
    for (auto& life : lives_) {
        life->draw(app);
    }
}
