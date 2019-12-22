#ifndef GRASS_H_
#define GRASS_H_

#include "platform.h"

class Player;

class Grass : public Platform {
 public:
    static void clearTopGrass() { top_ = nullptr; }

    Grass();
    ~Grass();
    void initialize();
    void update(Player* player);

 private:
    static Grass* top_;
};

#endif  // GRASS_H_
