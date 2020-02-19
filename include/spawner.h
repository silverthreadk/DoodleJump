#ifndef SPAWNER_H_
#define SPAWNER_H_

#include <memory>

#include "observer.h"

class Spawner {
 public:
    Spawner() {}
    virtual ~Spawner() {}
    virtual std::shared_ptr<Observer> spawnEntity() = 0;
};

template <class T>
class SpawnerFor : public Spawner {
 public:
    std::shared_ptr<Observer> spawnEntity() { return T::create(); }
};

#endif  // SPAWNER_H_
