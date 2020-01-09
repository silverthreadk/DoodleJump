#ifndef PLATFORM_H_
#define PLATFORM_H_

#include "observer.h"

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
