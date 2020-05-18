#ifndef ICE_H_
#define ICE_H_

#include <memory>

#include "entity/platform.h"

class Player;

class Ice : public Platform {
 public:
    static std::unique_ptr<Ice> create();
    ~Ice();
    void move(Player* player);

 private:
    Ice();

    int direction;
};

#endif  // ICE_H_
