#ifndef COIN_H_
#define COIN_H_

#include "observer.h"

class Coin : public Observer {
 public:
    Coin();
    ~Coin();
    void initialize();
    void update(Player* player);
    void move(Player* player) {}
    void fallen(Player* player);
};

#endif  // COIN_H_
