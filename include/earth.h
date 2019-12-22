#ifndef EARTH_H_
#define EARTH_H_

#include "platform.h"

class Player;

class Earth : public Platform {
 public:
    Earth();
    ~Earth();
    void update(Player* player);
    void fallen(Player* player);
};

#endif  // EARTH_H_
