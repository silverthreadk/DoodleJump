#ifndef LIFE_H_
#define LIFE_H_

#include "entity/entity.h"

class Life : public Entity {
 public:
    Life(sf::Texture* texture, const int x, const int y);
    ~Life();
};

#endif  // LIFE_H_
