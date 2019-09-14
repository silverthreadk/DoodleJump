#ifndef PLAT_H_
#define PLAT_H_

class Player;

namespace sf {
class RenderWindow;
class Sprite;
}

class Observer {
 public:
    virtual ~Observer() {}
    virtual void initialize() = 0;
    virtual void update(Player* player) = 0;
    virtual void calculate(Player* player) = 0;
    virtual void draw(sf::RenderWindow* app, sf::Sprite* sprite) = 0;
};

class Plat : public Observer {
 public:
    Plat();
    ~Plat() {}
    virtual void initialize();
    virtual void update(Player* player);
    virtual void calculate(Player* player);
    virtual void draw(sf::RenderWindow* app, sf::Sprite* sprite);

    int getX() { return x; }
    int getY() { return y; }

 private:
    int x;
    int y;
};

#endif  // PLAT_H_
