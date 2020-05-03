#include "game.h"

#include <time.h>
#include <string>

#include "resource_holder.h"
#include "config.h"
#include "input_handler.h"
#include "command.h"
#include "background.h"
#include "landscape.h"
#include "spawner.h"
#include "platform.h"
#include "starting_point.h"
#include "grass.h"
#include "stone.h"
#include "cloud.h"
#include "earth.h"
#include "ice.h"
#include "coin.h"
#include "player.h"
#include "score_board.h"
#include "life_board.h"

Game::Game()
    : app_(sf::VideoMode(kScreenWidth, kScreenHeight), "Doodle Game!"),
    state_(PLAYING),
    background_(nullptr),
    landscape_(new Landscape()),
    player_(nullptr),
    score_board_(nullptr),
    life_board_ (nullptr),
    input_handler_(new InputHandler()),
    difficulty_level_(0) {
    srand(time(0));

    loadResource();

    app_.setFramerateLimit(kIntialFrameRate);

    background_ = new Background();
    player_ = new Player(*this);
    score_board_ = new ScoreBoard();
    life_board_ = new LifeBoard();

    createPlatform();
    createCoin();
}

Game::~Game() {
    delete landscape_;
    delete player_;
    delete score_board_;
    delete life_board_;
    delete input_handler_;
}

void Game::initialize() {
    if (state_ != GAME_OVER) return;

    landscape_->onInitialize();
    score_board_->initialize();
    life_board_->initialize();

    state_ = PLAYING;
    difficulty_level_ = 0;
}

void Game::run() {
    while (app_.isOpen()) {
        sf::Event e;
        while (app_.pollEvent(e)) {
            if (e.type == sf::Event::Closed)
                close();
        }

        if (e.type != sf::Event::LostFocus) {
            handleInput();
        }

        layout();

        adjustDifficultyLevel();

        draw();
    }
}

void Game::close() {
    score_board_->save();
    app_.close();
}

void Game::loadResource() {
    TextureHolder* texture_holder = TextureHolder::getInstance();
    texture_holder->load(Textures::BACKGROUND, RESOURCE_PATH + "images/background.png");
    texture_holder->load(Textures::GRASS, RESOURCE_PATH + "images/grass.png");
    texture_holder->load(Textures::STONE, RESOURCE_PATH + "images/stone.png");
    texture_holder->load(Textures::CLOUD, RESOURCE_PATH + "images/cloud.png");
    texture_holder->load(Textures::EARTH, RESOURCE_PATH + "images/earth.png");
    texture_holder->load(Textures::ICE, RESOURCE_PATH + "images/ice.png");
    texture_holder->load(Textures::COIN, RESOURCE_PATH + "images/coin.png");
    texture_holder->load(Textures::DOODLE, RESOURCE_PATH + "images/doodle.png");

    FontHolder* font_holder = FontHolder::getInstance();
    font_holder->load(Fonts::MAIN, RESOURCE_PATH + "fonts/nanumgothic.ttf");
}

void Game::createPlatform() {
    SpawnerFor<StartingPoint> starting_point_spawner;
    landscape_->addObserver(std::move(starting_point_spawner.spawnEntity()));

    SpawnerFor<Grass> grass_spawner;
    for (int i = 0; i < 10; ++i) {
        landscape_->addObserver(std::move(grass_spawner.spawnEntity()));
    }

    SpawnerFor<Earth> earth_spawner;
    for (int i = 0; i < 3; ++i) {
        landscape_->addObserver(std::move(earth_spawner.spawnEntity()));
    }

    SpawnerFor<Cloud> cloud_spawner;
    for (int i = 0; i < 3; ++i) {
        landscape_->addObserver(std::move(cloud_spawner.spawnEntity()));
    }

    SpawnerFor<Stone> stone_spawner;
    landscape_->addObserver(std::move(stone_spawner.spawnEntity()));

    SpawnerFor<Ice> ice_spawner;
    landscape_->addObserver(std::move(ice_spawner.spawnEntity()));
}

void Game::createCoin() {
    SpawnerFor<Coin> coin_spawner;
    for (int i = 0; i < 5; ++i) {
        landscape_->addObserver(coin_spawner.spawnEntity());
    }
}

void Game::handleInput() {
    Command* command = input_handler_->handleInput();
    if (!command) return;

    command->execute(player_);
}

void Game::layout() {
    player_->drop();

    if (player_->isLowestPoint()) {
        player_->revive();
        life_board_->update();
    } else if (player_->isHighestPoint()) {
        player_->keepJumpHeight();

        landscape_->onUpdate(player_);
    }
    landscape_->onMove(player_);
    landscape_->onFallen(player_);
    score_board_->update(player_);
}

void Game::draw() {
    background_->draw(&app_);
    landscape_->onDraw(&app_);
    player_->draw(&app_);
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
