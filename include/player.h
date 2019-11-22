#ifndef PLAYER_H_
#define PLAYER_H_

#include "entity.h"

class Game;

class Player : public Entity {
 public:
    Player(Game& game, sf::Texture* texture);
    ~Player();
    void restart();
    void moveToLeft();
    void moveToRight();
    void drop();
    void jump();
    void revive();
    bool isLowestPoint() const;
    bool isHighestPoint();
    void addScore();
    double getVelocity() const { return velocity_; }
    int getScore() const { return score_; }
    int getLives() const { return lives_; }

 private:
    void initialize();

    Game& game_;
    double velocity_;
    const int jump_height_;
    int dy_;
    int lives_;
    int score_;
};

#endif  // PLAYER_H_
