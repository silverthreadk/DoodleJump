#include "game.h"

#include <time.h>
#include <string>

#include "config.h"
#include "input_handler.h"
#include "command.h"
#include "landscape.h"
#include "plat.h"
#include "player.h"

Game::Game() : app(sf::VideoMode(400, 533), "Doodle Game!"),
    state_(PLAYING),
    landscape_(new Landscape()),
    player_(new Player()),
    input_handler_(new InputHandler()) {
    srand(time(0));

    background_texture_.loadFromFile(RESOURCE_PATH + "images/background.png");
    platform_texture_.loadFromFile(RESOURCE_PATH + "images/platform.png");
    doodle_texture_.loadFromFile(RESOURCE_PATH + "images/doodle.png");
    font_.loadFromFile(RESOURCE_PATH + "fonts/nanumgothic.ttf");

    background_sprite_.setTexture(background_texture_);
    plat_sprite_.setTexture(platform_texture_);
    doodle_sprite_.setTexture(doodle_texture_);

    app.setFramerateLimit(60);

    game_over_text_.setFont(font_);
    game_over_text_.setCharacterSize(25);
    game_over_text_.setStyle(sf::Text::Bold);
    game_over_text_.setColor(sf::Color::Black);
    game_over_text_.setString("Press Enter to Continue");
    game_over_text_.setPosition(55, 230);

    score_text.setFont(font_);
    score_text.setCharacterSize(20);
    score_text.setStyle(sf::Text::Bold);
    score_text.setColor(sf::Color::Black);
    score_text.setPosition(10, 10);

    for (int i = 0; i < 10; i++) {
        std::shared_ptr<Plat> plat = std::make_shared<Plat>();
        landscape_->addObserver(plat);
    }
}

Game::~Game() {
    delete landscape_;
    delete player_;
    delete input_handler_;
}

void Game::gameLoop() {
    while (app.isOpen()) {
        sf::Event e;
        while (app.pollEvent(e)) {
            if (e.type == sf::Event::Closed)
                app.close();
        }

        Command* command = input_handler_->handleInput(state_== GAME_OVER);
        if (command) {
            command->execute(player_);
            if (state_ == GAME_OVER) {
                state_ = PLAYING;
                landscape_->onInitialize();
            }
        }

        score_text.setString("score : " + std::to_string(player_->getScore()));

        if (player_->update()) {
            state_ = GAME_OVER;
        }

        if (player_->isHighestPoint()) {
            landscape_->onUpdate(player_);
        }
        landscape_->onCalculate(player_);

        doodle_sprite_.setPosition(player_->getX(), player_->getY());

        draw();
    }
}

void Game::draw() {
    app.draw(background_sprite_);
    app.draw(doodle_sprite_);
    landscape_->onDraw(&app, &plat_sprite_);
    app.draw(score_text);
    if (state_ == GAME_OVER) {
        app.draw(game_over_text_);
    }

    app.display();
}