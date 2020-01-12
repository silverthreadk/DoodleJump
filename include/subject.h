#ifndef SUBJECT_H_
#define SUBJECT_H_

#include <list>
#include <memory>

class Observer;
class Player;

namespace sf {
    class RenderWindow;
}

class Subject {
 public:
    Subject() {}
    virtual ~Subject() {}
    void addObserver(std::shared_ptr<Observer> observer);
    void removeObserver(std::shared_ptr<Observer> observer);

 protected:
    void initialize();
    void update(Player* player);
    void move(Player* player);
    void fallen(Player* player);
    void draw(sf::RenderWindow* app);

 private:
    std::list<std::shared_ptr<Observer> > observers_;
};

#endif  // SUBJECT_H_
