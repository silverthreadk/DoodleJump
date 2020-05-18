#ifndef OBSERVER_H_
#define OBSERVER_H_

#include "entity/entity.h"

class Player;

class Observer : public Entity {
 public:
    explicit Observer(sf::Texture* texture) : Entity(texture) {}
    virtual ~Observer() {}
    virtual void initialize() = 0;
    virtual void move(Player* player) = 0;
    virtual void update(Player* player) = 0;
    virtual void fallen(Player* player) = 0;
};

#endif  // OBSERVER_H_
