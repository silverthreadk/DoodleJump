#include "life_board.h"

#include <life.h>

LifeBoard::LifeBoard(sf::Texture* texture_, const int lives) {
    int x = 400, y = 10;
    for (int i = 0; i < lives; ++i) {
        x = x - texture_->getSize().x / 2 - 5;
        lives_.push_back(std::make_shared<Life>(texture_, x, y));
    }
}

LifeBoard::~LifeBoard() {
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
