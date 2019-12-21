#include "game.h"

#include <time.h>
#include <string>

#include "resource_holder.h"
#include "config.h"
#include "input_handler.h"
#include "command.h"
#include "landscape.h"
#include "spawner.h"
#include "platform.h"
#include "grass.h"
#include "stone.h"
#include "earth.h"
#include "player.h"
#include "score_board.h"
#include "life_board.h"

Game::Game() : app_(sf::VideoMode(kScreenWidth, kScreenHeight), "Doodle Game!"),
    state_(PLAYING),
    landscape_(nullptr),
    input_handler_(new InputHandler()),
    difficulty_level_(0) {
    srand(time(0));

    loadResource();

    background_sprite_.setTexture(TextureHolder::getInstance()->get(Textures::BACKGROUND));

    app_.setFramerateLimit(kIntialFrameRate);

    player_ = new Player(*this);
    score_board_ = new ScoreBoard(&app_, *this);
    life_board_ = new LifeBoard(player_->getLives());

    initializePlatform();
}

Game::~Game() {
    delete landscape_;
    delete player_;
    delete score_board_;
    delete life_board_;
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

void Game::loadResource() {
    TextureHolder* texture_holder = TextureHolder::getInstance();
    texture_holder->load(Textures::BACKGROUND, RESOURCE_PATH + "images/background.png");
    texture_holder->load(Textures::GRASS, RESOURCE_PATH + "images/grass.png");
    texture_holder->load(Textures::STONE, RESOURCE_PATH + "images/stone.png");
    texture_holder->load(Textures::EARTH, RESOURCE_PATH + "images/earth.png");
    texture_holder->load(Textures::DOODLE, RESOURCE_PATH + "images/doodle.png");

    FontHolder* font_holder = FontHolder::getInstance();
    font_holder->load(Fonts::MAIN, RESOURCE_PATH + "fonts/nanumgothic.ttf");
}

void Game::initialize() {
    if (state_ != GAME_OVER) return;
    initializePlatform();
    score_board_->initialize();
    life_board_->initialize();

    state_ = PLAYING;
    difficulty_level_ = 0;
}

void Game::initializePlatform() {
    if (landscape_) delete landscape_;
    landscape_ = new Landscape();

    SpawnerFor<Grass> grass_spawner;
    for (int i = 0; i < 10; ++i) {
        landscape_->addObserver(grass_spawner.spawnPlatform());
    }

    SpawnerFor<Earth> earth_spawner;
    for (int i = 0; i < 3; ++i) {
        landscape_->addObserver(earth_spawner.spawnPlatform());
    }

    SpawnerFor<Stone> stone_spawner;
    landscape_->addObserver(stone_spawner.spawnPlatform());
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
    if (difficulty_level_ > kMaxDifficultyLevel) return;
    if (player_->getScore() < difficulty_level_ * 1000) return;

    ++difficulty_level_;
    app_.setFramerateLimit(difficulty_level_ * 10 + kIntialFrameRate);
}
