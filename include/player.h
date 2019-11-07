#ifndef PLAYER_H_
#define PLAYER_H_

#include "entity.h"

class Game;

class Player : public Entity {
 public:
    Player(Game& game, sf::Texture* texture);
    ~Player();
    void initialize();
    void moveToLeft();
    void moveToRight();
    bool update();
    void jump();
    bool isHighestPoint();
    void addScore();

    double getVelocity() { return dy; }
    int getScore() { return score; }

 private:
    Game& game_;
    double dy;
    const int jump_height;
    int score;
};

#endif  // PLAYER_H_
