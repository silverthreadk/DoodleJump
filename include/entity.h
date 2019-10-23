#ifndef ENTITY_H_
#define ENTITY_H_

namespace sf {
class RenderWindow;
class Sprite;
class Texture;
}

class Entity {
 public:
    explicit Entity(sf::Texture* texture);
    virtual ~Entity();
    void draw(sf::RenderWindow* app);

    int getX() { return x; }
    int getY() { return y; }

 protected:
    sf::Sprite* sprite_;
    int x;
    int y;
};

#endif  // ENTITY_H_
