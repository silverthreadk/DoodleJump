#ifndef LIFE_BOARD_H_
#define LIFE_BOARD_H_

#include <memory>
#include <vector>

namespace sf {
    class RenderWindow;
}

class Life;

class LifeBoard {
 public:
    LifeBoard();
    ~LifeBoard();
    void initialize();
    void update();
    void draw(sf::RenderWindow* app);

 private:
    std::vector<std::unique_ptr<Life> > lives_;
    int life_index_;
};

#endif  // LIFE_BOARD_H_
