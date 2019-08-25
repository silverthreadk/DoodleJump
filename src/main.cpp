#include <SFML/Graphics.hpp>
#include <time.h>

#include "config.h"
#include "input_handler.h"
#include "command.h"
#include "landscape.h"
#include "plat.h"

using namespace sf;

struct point
{ int x,y;};

int main() {
    srand(time(0));

    RenderWindow app(VideoMode(400, 533), "Doodle Game!");
    app.setFramerateLimit(60);

    Texture t1,t2,t3;
    t1.loadFromFile(RESOURCE_PATH + "images/background.png");
    t2.loadFromFile(RESOURCE_PATH + "images/platform.png");
    t3.loadFromFile(RESOURCE_PATH + "images/doodle.png");

    Sprite sBackground(t1), sPlat(t2), sPers(t3);

    Landscape landscape;
    for (int i = 0; i < 10; i++) {
        std::shared_ptr<Plat> plat = std::make_shared<Plat>();
        landscape.addObserver(plat);
    }

    int x=100,y=100,h=200;
    float dx=0,dy=0;

    InputHandler ih;
    Command* command;

    while (app.isOpen()) {
        Event e;
        while (app.pollEvent(e)) {
            if (e.type == Event::Closed)
                app.close();
        }

        command = ih.handleInput();
        if (command) command->execute(&x);

        dy += 0.2;
        y += dy;
        if (y > 500)  dy = -10;

        if (y < h) {
            y = h;
            landscape.onUpdate(dy);
        }
        landscape.onCalculate(x, y, &dy);

        sPers.setPosition(x, y);

        app.draw(sBackground);
        app.draw(sPers);
        landscape.onDraw(&app,&sPlat);

        app.display();
    }

    return 0;
}
