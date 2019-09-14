#include "landscape.h"

#include <SFML/Graphics.hpp>

#include "plat.h"
#include "player.h"

void Subject::addObserver(std::shared_ptr<Observer> observer) {
    observers_.push_back(observer);
}

void Subject::removeObserver(std::shared_ptr<Observer> observer) {
    observers_.remove(observer);
}

void Subject::initialize() {
    for (auto observer = observers_.begin(); observer != observers_.end(); ++observer) {
        (*observer)->initialize();
    }
}

void Subject::update(Player* player) {
    for (auto observer = observers_.begin(); observer != observers_.end(); ++observer) {
        (*observer)->update(player);
    }
}

void Subject::calculate(Player* player) {
    for (auto observer = observers_.begin(); observer != observers_.end(); ++observer) {
        (*observer)->calculate(player);
    }
}

void Subject::draw(sf::RenderWindow* app, sf::Sprite* sprite) {
    for (auto observer = observers_.begin(); observer != observers_.end(); ++observer) {
        (*observer)->draw(app, sprite);
    }
}

void Landscape::onInitialize() {
    initialize();
}

void Landscape::onUpdate(Player* player) {
    update(player);
}

void Landscape::onCalculate(Player* player) {
    calculate(player);
}

void Landscape::onDraw(sf::RenderWindow* app, sf::Sprite* sprite) {
    draw(app, sprite);
}
