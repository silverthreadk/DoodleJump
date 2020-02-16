#include "landscape.h"

#include <SFML/Graphics.hpp>

Landscape::Landscape() {
}

Landscape::~Landscape() {
}

void Landscape::onInitialize() {
    initialize();
}

void Landscape::onUpdate(Player* player) {
    update(player);
}

void Landscape::onMove(Player* player) {
    move(player);
}

void Landscape::onFallen(Player* player) {
    fallen(player);
}

void Landscape::onDraw(sf::RenderWindow* app) {
    draw(app);
}
