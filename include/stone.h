#ifndef STONE_H_
#define STONE_H_

#include <memory>

#include "platform.h"

class Stone : public Platform {
 public:
    static std::shared_ptr<Stone> create();
    ~Stone();

 private:
    Stone();
};

#endif  // STONE_H_
