#ifndef PLAYER_H_
#define PLAYER_H_

#include "entity/entity.h"

class Game;

class Player : public Entity {
 public:
    Player(Game& game);
    ~Player();
    void restart();
    void close();
    void moveToLeft();
    void moveToRight();
    void drop();
    void jump(const int velocity);
    void revive();
    bool isLowestPoint() const;
    bool isHighestPoint() const;
    void keepJumpHeight();
    void earnCoin();
    double getVelocity() const { return velocity_; }
    int getScore() const { return score_; }
    int getLives() const { return lives_; }

 private:
    void initialize();
    void initializeLocation();
    void calculateScore();

    Game& game_;
    double velocity_;
    int altitude_;
    int coin_;
    int lives_;
    int score_;
};

#endif  // PLAYER_H_
