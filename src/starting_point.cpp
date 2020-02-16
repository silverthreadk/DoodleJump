#include "starting_point.h"

#include <SFML/Graphics.hpp>

#include "config.h"

std::shared_ptr<Platform> StartingPoint::create() {
    std::shared_ptr<Platform> platform(new StartingPoint);
    platform->initialize();
    return platform;
}

StartingPoint::StartingPoint() : Grass() {
}

StartingPoint::~StartingPoint() {
}

void StartingPoint::initialize() {
    top_ = y_ = kScreenHeight;
}
