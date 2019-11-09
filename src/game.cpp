#include "game.h"

#include <time.h>
#include <string>

#include "config.h"
#include "input_handler.h"
#include "command.h"
#include "landscape.h"
#include "platform.h"
#include "player.h"
#include "score_board.h"

Game::Game() : screen_width_(400),
    screen_height_(533),
    app(sf::VideoMode(screen_width_, screen_height_), "Doodle Game!"),
    state_(GAME_OVER),
    landscape_(new Landscape()),
    input_handler_(new InputHandler())  {
    srand(time(0));

    background_texture_.loadFromFile(RESOURCE_PATH + "images/background.png");
    platform_texture_.loadFromFile(RESOURCE_PATH + "images/platform.png");
    doodle_texture_.loadFromFile(RESOURCE_PATH + "images/doodle.png");
    font_.loadFromFile(RESOURCE_PATH + "fonts/nanumgothic.ttf");

    background_sprite_.setTexture(background_texture_);
    doodle_sprite_.setTexture(doodle_texture_);

    app.setFramerateLimit(60);

    player_ = new Player(*this, &doodle_texture_);
    score_board_ = new ScoreBoard(&app, &font_);

    for (int i = 0; i < 10; i++) {
        std::shared_ptr<Platform> plat = std::make_shared<Platform>(&platform_texture_);
        landscape_->addObserver(plat);
    }
}

Game::~Game() {
    delete landscape_;
    delete player_;
    delete score_board_;
    delete input_handler_;
}

void Game::gameLoop() {
    state_ = PLAYING;

    while (app.isOpen()) {
        sf::Event e;
        while (app.pollEvent(e)) {
            if (e.type == sf::Event::Closed)
                app.close();
        }

        if (e.type != sf::Event::LostFocus && handleInput()) {
            initialize();
        }

        layout();

        draw();
    }
}

bool Game::handleInput() {
    Command* command = input_handler_->handleInput();
    if (!command) return false;

    command->execute(player_);
    return true;
}

void Game::initialize() {
    if (state_ != GAME_OVER) return;

    state_ = PLAYING;
    landscape_->onInitialize();
}

void Game::layout() {
    player_->drop();

    if (player_->isLowestPoint()) {
        state_ = GAME_OVER;
    } else if (player_->isHighestPoint()) {
        landscape_->onUpdate(player_);
    }
    landscape_->onCalculate(player_);

    score_board_->update(player_->getScore());
}

void Game::draw() {
    app.draw(background_sprite_);
    player_->draw(&app);
    landscape_->onDraw(&app);
    score_board_->draw(&app, state_ == GAME_OVER);

    app.display();
}
