#ifndef STARTING_POINT_H_
#define STARTING_POINT_H_

#include "entity/grass.h"

class StartingPoint : public Grass {
 public:
    static std::unique_ptr<StartingPoint> create();
    ~StartingPoint();
    void initialize();
    void update(Player* player) {}
    void move(Player* player) {}
    void fallen(Player* player) {}

 private:
    StartingPoint();
};

#endif  // STARTING_POINT_H_
