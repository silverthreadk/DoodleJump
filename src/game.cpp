#include "game.h"

#include <time.h>
#include <string>

#include "config.h"
#include "input_handler.h"
#include "command.h"
#include "landscape.h"
#include "platform.h"
#include "player.h"

Game::Game() : screen_width_(400),
    screen_height_(533),
    app(sf::VideoMode(screen_width_, screen_height_), "Doodle Game!"),
    state_(PLAYING),
    landscape_(new Landscape()),
    input_handler_(new InputHandler()),
    high_score_(0) {
    srand(time(0));

    background_texture_.loadFromFile(RESOURCE_PATH + "images/background.png");
    platform_texture_.loadFromFile(RESOURCE_PATH + "images/platform.png");
    doodle_texture_.loadFromFile(RESOURCE_PATH + "images/doodle.png");
    font_.loadFromFile(RESOURCE_PATH + "fonts/nanumgothic.ttf");

    background_sprite_.setTexture(background_texture_);
    doodle_sprite_.setTexture(doodle_texture_);

    app.setFramerateLimit(60);

    auto initialize_text = [this](int font_size, sf::Text* text) {
        text->setFont(font_);
        text->setCharacterSize(font_size);
        text->setStyle(sf::Text::Bold);
        text->setColor(sf::Color::Black);
    };

    initialize_text(25, &game_over_text_);
    game_over_text_.setString("Press Enter to Continue");
    sf::FloatRect text_rect = game_over_text_.getLocalBounds();
    game_over_text_.setOrigin(text_rect.left + text_rect.width / 2.0f,
        text_rect.top + text_rect.height / 2.0f);
    game_over_text_.setPosition(sf::Vector2f(screen_width_ / 2.f, -text_rect.height + screen_height_ / 2.f));

    initialize_text(20, &high_score_text_);
    high_score_text_.setOrigin(text_rect.left + text_rect.width / 2.0f,
        text_rect.top + text_rect.height / 2.0f);
    high_score_text_.setPosition(screen_width_ / 2.f, text_rect.height + screen_height_ / 2.f );

    initialize_text(20, &score_text_);
    score_text_.setPosition(10, 10);

    player_ = new Player(&doodle_texture_);

    for (int i = 0; i < 10; i++) {
        std::shared_ptr<Platform> plat = std::make_shared<Platform>(&platform_texture_);
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

        score_text_.setString("score : " + std::to_string(player_->getScore()));
        high_score_text_.setString("high score : " + std::to_string(high_score_));

        if (player_->update()) {
            state_ = GAME_OVER;
            high_score_ = std::max(high_score_, player_->getScore());
        }

        if (player_->isHighestPoint()) {
            landscape_->onUpdate(player_);
        }
        landscape_->onCalculate(player_);

        draw();
    }
}

void Game::draw() {
    app.draw(background_sprite_);
    player_->draw(&app);
    landscape_->onDraw(&app);
    app.draw(score_text_);
    if (state_ == GAME_OVER) {
        app.draw(game_over_text_);
        app.draw(high_score_text_);
    }

    app.display();
}