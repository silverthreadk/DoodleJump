#ifndef SPAWNER_H_
#define SPAWNER_H_

#include <memory>

#include "platform.h"

class Spawner {
 public:
    Spawner() {}
    virtual ~Spawner() {}
    virtual std::shared_ptr<Platform> spawnPlatform() = 0;
};

template <class T>
class SpawnerFor : public Spawner {
 public:
    std::shared_ptr<Platform> spawnPlatform() { return T::create(); }
};

#endif  // SPAWNER_H_
