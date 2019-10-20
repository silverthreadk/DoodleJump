#ifndef PLATFORM_H_
#define PLATFORM_H_

class Player;

namespace sf {
class RenderWindow;
class Sprite;
class Texture;
}

class Observer {
 public:
    virtual ~Observer() {}
    virtual void initialize() = 0;
    virtual void update(Player* player) = 0;
    virtual void calculate(Player* player) = 0;
    virtual void draw(sf::RenderWindow* app) = 0;
};

class Platform : public Observer {
 public:
    Platform(sf::Texture* texture);
    ~Platform();
    virtual void initialize();
    virtual void update(Player* player);
    virtual void calculate(Player* player);
    virtual void draw(sf::RenderWindow* app);

    int getX() { return x; }
    int getY() { return y; }

 private:
    sf::Sprite* sprite_;
    int x;
    int y;
};

#endif  // PLAT_H_
