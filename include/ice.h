#ifndef ICE_H_
#define ICE_H_

#include "platform.h"

class Player;

class Ice : public Platform {
 public:
    Ice();
    ~Ice();
    void move(Player* player);

private:
    int direction;
};

#endif  // ICE_H_
