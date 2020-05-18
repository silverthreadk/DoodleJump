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
    Entity(sf::Texture* texture, const int x, const int y);
    Entity(sf::Texture* texture, const int x, const int y, const int horizontal_padding);
    virtual ~Entity();
    virtual void draw(sf::RenderWindow* app);
    void setHidden(const bool hidden);
    bool isHidden() const;
    bool isOverlapped(Entity* entity) const;
    bool isOverlappedToBottom(Entity* entity) const;

 protected:
    int getLeft() const { return x_; }
    int getTop() const { return y_; }
    int getRight() const;
    int getBottom() const;
    int getWidth() const;
    int getHeight() const;
    int getMaxX() const;
    int getMaxY() const;

    sf::Sprite* sprite_;
    int x_;
    int y_;
    int horizontal_padding_;
};

#endif  // ENTITY_H_
