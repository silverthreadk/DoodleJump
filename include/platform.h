#ifndef PLATFORM_H_
#define PLATFORM_H_

#include "entity.h"

class Player;

class Observer : public Entity {
 public:
    explicit Observer(sf::Texture* texture) : Entity(texture) {}
    virtual ~Observer() {}
    virtual void initialize() = 0;
    virtual void update(Player* player) = 0;
    virtual void calculate(Player* player) = 0;
};

class Platform : public Observer {
 public:
    explicit Platform(sf::Texture* texture);
    ~Platform();
    void initialize();
    void update(Player* player);
    void calculate(Player* player);
};

#endif  // PLAT_H_
