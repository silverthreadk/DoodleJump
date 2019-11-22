#ifndef LIFE_BOARD_H_
#define LIFE_BOARD_H_

#include <memory>
#include <vector>

#include <SFML/Graphics.hpp>

class Life;

class LifeBoard {
 public:
     LifeBoard(sf::Texture* texture, const int lives);
    ~LifeBoard();
    void update();
    void draw(sf::RenderWindow* app);

 private:
    std::vector<std::shared_ptr<Life> > lives_;
};

#endif  // LIFE_BOARD_H_
