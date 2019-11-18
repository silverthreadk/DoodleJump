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
    virtual void draw(sf::RenderWindow* app);
    bool isIntersecting(Entity* entity) const;

 protected:
    int getLeft() const { return x_; }
    int getTop() const { return y_; }
    int getBottom() const;
    int getRight() const;

    sf::Sprite* sprite_;
    int x_;
    int y_;
    int horizontal_padding_;
};

#endif  // ENTITY_H_
