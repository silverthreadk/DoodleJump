#ifndef LANDSCAPE_H_
#define LANDSCAPE_H_

#include "subject.h"

class Landscape : public Subject {
 public:
    Landscape();
    ~Landscape();
    void onInitialize();
    void onUpdate(Player* player);
    void onMove(Player* player);
    void onFallen(Player* player);
    void onDraw(sf::RenderWindow* app);
};

#endif  // LANDSCAPE_H_
