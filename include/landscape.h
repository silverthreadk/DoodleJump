#ifndef LANDSCAPE_H_
#define LANDSCAPE_H_

#include <list>
#include <memory>

class Observer;
class Player;

namespace sf {
class RenderWindow;
class Sprite;
}

class Subject {
 public:
    void addObserver(std::shared_ptr<Observer> observer);
    void removeObserver(std::shared_ptr<Observer> observer);

 protected:
    void initialize();
    void update(Player* player);
    void calculate(Player* player);
    void draw(sf::RenderWindow* app, sf::Sprite* sprite);

 private:
    std::list<std::shared_ptr<Observer> > observers_;
};

class Landscape : public Subject {
 public:
    void onInitialize();
    void onUpdate(Player* player);
    void onCalculate(Player* player);
    void onDraw(sf::RenderWindow* app, sf::Sprite* sprite);
};
#endif  // LANDSCAPE_H_
