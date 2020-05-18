#ifndef GRASS_H_
#define GRASS_H_

#include <memory>

#include "entity/platform.h"

class Player;

class Grass : public Platform {
 public:
    static std::unique_ptr<Grass> create();
    ~Grass();
    void initialize();
    void update(Player* player);

 protected:
    Grass();

    static int top_;
};

#endif  // GRASS_H_
