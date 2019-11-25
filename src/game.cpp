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
#include "life_board.h"

Game::Game() : screen_width_(400),
    screen_height_(533),
    max_difficulty_level_(6),
    intial_frame_rate_(60),
    app_(sf::VideoMode(screen_width_, screen_height_), "Doodle Game!"),
    state_(PLAYING),
    landscape_(nullptr),
    input_handler_(new InputHandler()),
    difficulty_level_(0) {
    srand(time(0));

    background_texture_.loadFromFile(RESOURCE_PATH + "images/background.png");
    lawn_texture_.loadFromFile(RESOURCE_PATH + "images/grass.png");
    stone_texture_.loadFromFile(RESOURCE_PATH + "images/stone.png");
    doodle_texture_.loadFromFile(RESOURCE_PATH + "images/doodle.png");
    font_.loadFromFile(RESOURCE_PATH + "fonts/nanumgothic.ttf");

    background_sprite_.setTexture(background_texture_);
    doodle_sprite_.setTexture(doodle_texture_);

    app_.setFramerateLimit(intial_frame_rate_);

    player_ = new Player(*this, &doodle_texture_);
    score_board_ = new ScoreBoard(&app_, &font_, *this);
    life_board_ = new LifeBoard(&doodle_texture_, player_->getLives());

    initializePlatform();
}

Game::~Game() {
    delete landscape_;
    delete player_;
    delete score_board_;
    delete input_handler_;
}

void Game::run() {
    while (app_.isOpen()) {
        sf::Event e;
        while (app_.pollEvent(e)) {
            if (e.type == sf::Event::Closed)
                app_.close();
        }

        if (e.type != sf::Event::LostFocus) {
            handleInput();
        }

        layout();

        adjustDifficultyLevel();

        draw();
    }
}

void Game::handleInput() {
    Command* command = input_handler_->handleInput();
    if (!command) return;

    command->execute(player_);
}

void Game::initialize() {
    if (state_ != GAME_OVER) return;
    initializePlatform();

    state_ = PLAYING;
    difficulty_level_ = 0;
}

void Game::initializePlatform() {
    if (landscape_) delete landscape_;
    landscape_ = new Landscape();

    for (int i = 0; i < 10; i++) {
        std::shared_ptr<Platform> plat = std::make_shared<Platform>(&lawn_texture_, Platform::GRASS, -10);
        landscape_->addObserver(plat);
    }

    std::shared_ptr<Platform> plat = std::make_shared<Platform>(&stone_texture_, Platform::STONE, -5);
    landscape_->addObserver(plat);
}

void Game::layout() {
    player_->drop();

    if (player_->isLowestPoint()) {
        player_->revive();
        life_board_->update();
    } else if (player_->isHighestPoint()) {
        player_->addScore();
        score_board_->update(player_->getScore());

        landscape_->onUpdate(player_);
    }
    landscape_->onFallen(player_);
}

void Game::draw() {
    app_.draw(background_sprite_);
    player_->draw(&app_);
    landscape_->onDraw(&app_);
    score_board_->draw(&app_);
    life_board_->draw(&app_);

    app_.display();
}

void Game::adjustDifficultyLevel() {
    if (difficulty_level_ > max_difficulty_level_) return;
    if (player_->getScore() < difficulty_level_ * 1000) return;

    ++difficulty_level_;
    app_.setFramerateLimit(difficulty_level_ * 10 + intial_frame_rate_);
}
