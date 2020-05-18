#include "entity/starting_point.h"

#include <SFML/Graphics.hpp>

#include "config.h"

std::unique_ptr<StartingPoint> StartingPoint::create() {
    std::unique_ptr<StartingPoint> starting_point(new StartingPoint);
    starting_point->initialize();
    return starting_point;
}

StartingPoint::StartingPoint() : Grass() {
}

StartingPoint::~StartingPoint() {
}

void StartingPoint::initialize() {
    top_ = y_ = kScreenHeight;
}
