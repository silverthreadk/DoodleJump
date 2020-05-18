#ifndef PLATFORM_H_
#define PLATFORM_H_

#include "entity/observer.h"

class Platform : public Observer {
 public:
    ~Platform();
    void initialize();
    void update(Player* player);
    void move(Player* player) {}
    void fallen(Player* player);

 protected:
    Platform(sf::Texture* texture, const int velocity);

    const int velocity_;
};

#endif  // PLATFORM_H_
