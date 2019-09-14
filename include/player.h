#ifndef PLAYER_H_
#define PLAYER_H_

class Player {
 public:
    Player();
    ~Player() {}
    void initialize();
    void moveToLeft();
    void moveToRight();
    bool update();
    void jump();
    bool isHighestPoint();
    void addScore();

    int getX() { return x; }
    int getY() { return y; }
    double getVelocity() { return dy; }
    int getScore() { return score; }

 private:
    int x;
    int y;
    double dy;
    const int jump_height;
    int score;
};

#endif  // PLAYER_H_
