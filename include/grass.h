#ifndef GRASS_H_
#define GRASS_H_

#include <memory>

#include "platform.h"

class Player;

class Grass : public Platform {
 public:
    static std::shared_ptr<Platform> create();
    static void clearTopGrass() { top_ = nullptr; }
    ~Grass();
    void initialize();
    void update(Player* player);

 private:
    Grass();

    static Grass* top_;
};

#endif  // GRASS_H_
