#include "subject.h"

#include <SFML/Graphics.hpp>

#include "observer.h"
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
