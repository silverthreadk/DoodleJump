#include "subject.h"

#include <SFML/Graphics.hpp>

#include "entity/observer.h"
#include "entity/player.h"

Subject::Subject() {
}

Subject::~Subject() {
}

void Subject::addObserver(std::unique_ptr<Observer> observer) {
    observers_.push_back(std::move(observer));
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

void Subject::move(Player* player) {
    for (auto observer = observers_.begin(); observer != observers_.end(); ++observer) {
        (*observer)->move(player);
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
