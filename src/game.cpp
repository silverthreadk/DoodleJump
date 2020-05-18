#include "game.h"

#include <time.h>
#include <string>

#include "config.h"
#include "resource_manager.h"
#include "input_handler.h"
#include "command.h"
#include "landscape.h"
#include "spawner.h"
#include "score_board.h"
#include "life_board.h"
#include "entity/background.h"
#include "entity/platform.h"
#include "entity/starting_point.h"
#include "entity/grass.h"
#include "entity/stone.h"
#include "entity/cloud.h"
#include "entity/earth.h"
#include "entity/ice.h"
#include "entity/coin.h"
#include "entity/player.h"


Game::Game()
    : app_(sf::VideoMode(kScreenWidth, kScreenHeight), "Doodle Game!"),
    state_(PLAYING),
    resource_manager_(std::unique_ptr<ResourceManager>(new ResourceManager())),
    background_(std::unique_ptr<Background>(new Background())),
    landscape_(std::unique_ptr<Landscape>(new Landscape())),
    player_(std::unique_ptr<Player>(new Player(*this))),
    score_board_(std::unique_ptr<ScoreBoard>(new ScoreBoard())),
    life_board_ (std::unique_ptr<LifeBoard>(new LifeBoard())),
    input_handler_(std::unique_ptr<InputHandler>(new InputHandler())),
    difficulty_level_(0) {
    srand(time(0));

    app_.setFramerateLimit(kIntialFrameRate);

    createPlatform();
    createCoin();
}

Game::~Game() {
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

    command->execute(player_.get());
}

void Game::layout() {
    player_->drop();

    if (player_->isLowestPoint()) {
        player_->revive();
        life_board_->update();
    } else if (player_->isHighestPoint()) {
        player_->keepJumpHeight();

        landscape_->onUpdate(player_.get());
    }
    landscape_->onMove(player_.get());
    landscape_->onFallen(player_.get());
    score_board_->update(player_.get());
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
