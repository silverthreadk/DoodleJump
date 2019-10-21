#ifndef PLAYER_H_
#define PLAYER_H_

namespace sf {
    class RenderWindow;
    class Texture;
    class Sprite;
}

class Player {
 public:
    Player(sf::Texture* texture);
    ~Player() {}
    void initialize();
    void moveToLeft();
    void moveToRight();
    bool update();
    void jump();
    bool isHighestPoint();
    void addScore();
    void draw(sf::RenderWindow* app);

    int getX() { return x; }
    int getY() { return y; }
    double getVelocity() { return dy; }
    int getScore() { return score; }

 private:
    sf::Sprite* sprite_;
    int x;
    int y;
    double dy;
    const int jump_height;
    int score;
};

#endif  // PLAYER_H_
