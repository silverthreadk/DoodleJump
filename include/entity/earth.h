#ifndef EARTH_H_
#define EARTH_H_

#include <memory>

#include "entity/platform.h"

class Player;

class Earth : public Platform {
 public:
    static std::unique_ptr<Earth> create();
    ~Earth();
    void fallen(Player* player);

 private:
    Earth();
};

#endif  // EARTH_H_
