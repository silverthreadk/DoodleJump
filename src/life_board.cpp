#include "life_board.h"

#include <life.h>
#include <resource_holder.h>

LifeBoard::LifeBoard(const int lives) : num_of_lives_(lives) {
    initialize();
}

LifeBoard::~LifeBoard() {
}

void LifeBoard::initialize() {
    int x = 400, y = 10;
    sf::Texture& texture = TextureHolder::getInstance()->get(Textures::DOODLE);
    for (int i = 0; i < num_of_lives_; ++i) {
        x = x - texture.getSize().x / 2 - 5;
        lives_.push_back(std::make_shared<Life>(&texture, x, y));
    }
}

void LifeBoard::update() {
    if (lives_.empty()) return;
    lives_.pop_back();
}

void LifeBoard::draw(sf::RenderWindow* app) {
    for (auto& life : lives_) {
        life->draw(app);
    }
}
