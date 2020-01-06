#ifndef CLOUD_H_
#define CLOUD_H_

#include <memory>

#include "platform.h"

class Player;

class Cloud : public Platform {
 public:
    static std::shared_ptr<Platform> create();
    ~Cloud();
    void fallen(Player* player);

 private:
     Cloud();
};

#endif  // CLOUD_H_
