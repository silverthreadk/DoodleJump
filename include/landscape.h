#ifndef LANDSCAPE_H_
#define LANDSCAPE_H_

#include <list>
#include <memory>

class Observer;

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
    void update(int dy, int* score);
    void calculate(int x, int y, float* dy);
    void draw(sf::RenderWindow* app, sf::Sprite* sprite);

 private:
    std::list<std::shared_ptr<Observer> > observers_;
};

class Landscape : public Subject {
 public:
    void onInitialize();
    void onUpdate(int dy, int* score);
    void onCalculate(int x, int y, float* dy);
    void onDraw(sf::RenderWindow* app, sf::Sprite* sprite);
};
#endif  // LANDSCAPE_H_
