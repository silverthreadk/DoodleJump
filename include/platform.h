#ifndef PLATFORM_H_
#define PLATFORM_H_

#include "entity.h"

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

class Platform : public Observer {
 public:
    enum PLATFORM_TYPE { GRASS, STONE, CLOUD, EARTH, ICE };

    ~Platform();
    void initialize();
    void update(Player* player);
    void move(Player* player) {}
    void fallen(Player* player);

 protected:
    Platform(sf::Texture* texture, PLATFORM_TYPE type, const int velocity);

    PLATFORM_TYPE type_;
    const int velocity_;
};

#endif  // PLATFORM_H_
