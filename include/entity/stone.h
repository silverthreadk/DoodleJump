#ifndef STONE_H_
#define STONE_H_

#include <memory>

#include "entity/platform.h"

class Stone : public Platform {
 public:
    static std::unique_ptr<Stone> create();
    ~Stone();

 private:
    Stone();
};

#endif  // STONE_H_
