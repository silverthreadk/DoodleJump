#include "landscape.h"

#include <SFML/Graphics.hpp>

#include "platform.h"
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

void Subject::fallen(Player* player) {
    for (auto observer = observers_.begin(); observer != observers_.end(); ++observer) {
        (*observer)->fallen(player);
    }
}

void Subject::draw(sf::RenderWindow* app) {
    for (auto observer = observers_.begin(); observer != observers_.end(); ++observer) {
        (*observer)->draw(app);
    }
}

void Landscape::onInitialize() {
    initialize();
}

void Landscape::onUpdate(Player* player) {
    update(player);
}

void Landscape::onFallen(Player* player) {
    fallen(player);
}

void Landscape::onDraw(sf::RenderWindow* app) {
    draw(app);
}
