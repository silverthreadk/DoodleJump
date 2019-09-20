#include "game.h"

#include <time.h>
#include <string>
#include <SFML/Graphics.hpp>

#include "config.h"
#include "input_handler.h"
#include "command.h"
#include "landscape.h"
#include "plat.h"
#include "player.h"

Game::Game() {
}

Game::~Game() {
}

void Game::gameLoop() {
    srand(time(0));

    const int screen_width = 400;
    const int screen_height = 533;

    sf::RenderWindow app(sf::VideoMode(screen_width, screen_height), "Doodle Game!");
    app.setFramerateLimit(60);

    sf::Texture t1, t2, t3;
    t1.loadFromFile(RESOURCE_PATH + "images/background.png");
    t2.loadFromFile(RESOURCE_PATH + "images/platform.png");
    t3.loadFromFile(RESOURCE_PATH + "images/doodle.png");

    sf::Font font;
    font.loadFromFile(RESOURCE_PATH + "fonts/nanumgothic.ttf");

    sf::Sprite sBackground(t1), sPlat(t2), sPers(t3);

    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(25);
    text.setStyle(sf::Text::Bold);
    text.setColor(sf::Color::Black);
    text.setString("Press Enter to Continue");
    text.setPosition(55, 230);

    sf::Text score_text;
    score_text.setFont(font);
    score_text.setCharacterSize(20);
    score_text.setStyle(sf::Text::Bold);
    score_text.setColor(sf::Color::Black);
    score_text.setPosition(10, 10);

    Landscape landscape;
    for (int i = 0; i < 10; i++) {
        std::shared_ptr<Plat> plat = std::make_shared<Plat>();
        landscape.addObserver(plat);
    }

    Player player;

    InputHandler ih;
    Command* command;
    bool game_over = false;

    while (app.isOpen()) {
        sf::Event e;
        while (app.pollEvent(e)) {
            if (e.type == sf::Event::Closed)
                app.close();
        }

        command = ih.handleInput(game_over);
        if (command) {
            command->execute(&player);
            if (game_over) {
                landscape.onInitialize();
            }
        }

        score_text.setString("score : " + std::to_string(player.getScore()));

        game_over = player.update();

        if (player.isHighestPoint()) {
            landscape.onUpdate(&player);
        }
        landscape.onCalculate(&player);

        sPers.setPosition(player.getX(), player.getY());

        app.draw(sBackground);
        app.draw(sPers);
        landscape.onDraw(&app, &sPlat);
        app.draw(score_text);
        if (game_over) {
            app.draw(text);
        }

        app.display();
    }
}