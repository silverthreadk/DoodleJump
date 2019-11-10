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
    void drop();
    void jump();
    bool isLowestPoint();
    bool isHighestPoint();
    void addScore();

    double getVelocity() { return velocity_; }
    int getScore() { return score; }

 private:
    Game& game_;
    double velocity_;
    const int jump_height_;
    int dy_;
    int score;
};

#endif  // PLAYER_H_
