#ifndef CLOUD_H_
#define CLOUD_H_

#include <memory>

#include "entity/platform.h"

class Player;

class Cloud : public Platform {
 public:
    static std::unique_ptr<Cloud> create();
    ~Cloud();
    void fallen(Player* player);

 private:
     Cloud();
};

#endif  // CLOUD_H_
