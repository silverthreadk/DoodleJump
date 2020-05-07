#ifndef SPAWNER_H_
#define SPAWNER_H_

#include <memory>

class Observer;

class Spawner {
 public:
    Spawner() {}
    virtual ~Spawner() {}
    virtual std::unique_ptr<Observer> spawnEntity() = 0;
};

template <class T>
class SpawnerFor : public Spawner {
 public:
    std::unique_ptr<Observer> spawnEntity() { return T::create(); }
};

#endif  // SPAWNER_H_
