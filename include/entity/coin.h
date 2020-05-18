#ifndef COIN_H_
#define COIN_H_

#include <memory>

#include "entity/observer.h"

class Coin : public Observer {
 public:
    static std::unique_ptr<Coin> create();
    Coin();
    ~Coin();
    void initialize();
    void update(Player* player);
    void move(Player* player) {}
    void fallen(Player* player);
};

#endif  // COIN_H_
