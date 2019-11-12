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
    bool isIntersecting(Entity* entity) const;

 protected:
    int getLeft() const { return x; }
    int getTop() const { return y; }
    int getBottom() const;
    int getRight() const;

    sf::Sprite* sprite_;
    int x;
    int y;
    int horizontal_padding;
};

#endif  // ENTITY_H_
