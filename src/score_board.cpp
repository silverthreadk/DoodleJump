#include "score_board.h"

#include <string>
#include <fstream>
#include <iostream>

#include "game.h"
#include "config.h"
#include "resource_holder.h"

static void initilazeText(sf::Font* font, int font_size, sf::Text* text) {
    text->setFont(*font);
    text->setCharacterSize(font_size);
    text->setStyle(sf::Text::Bold);
    text->setColor(sf::Color::Black);
}

ScoreBoard::ScoreBoard(sf::RenderWindow* app, Game& game) :
    game_(game),
    high_score_(0) {
    sf::Font* font = &FontHolder::getInstance()->get(Fonts::MAIN);

    initilazeText(font, 25, &game_over_text_);
    game_over_text_.setString("Press Enter to Continue");
    sf::FloatRect text_rect = game_over_text_.getLocalBounds();
    game_over_text_.setOrigin(text_rect.left + text_rect.width / 2.0f,
        text_rect.top + text_rect.height / 2.0f);
    game_over_text_.setPosition(sf::Vector2f(app->getSize().x / 2.f, -text_rect.height + app->getSize().y / 2.f));

    initilazeText(font, 20, &high_score_text_);
    high_score_text_.setOrigin(text_rect.left + text_rect.width / 2.0f,
        text_rect.top + text_rect.height / 2.0f);
    high_score_text_.setPosition(app->getSize().x / 2.f, text_rect.height + app->getSize().y / 2.f);

    initilazeText(font, 20, &score_text_);
    score_text_.setPosition(10, 10);
    initialize();
    load();
}

ScoreBoard::~ScoreBoard() {
}

void ScoreBoard::initialize() {
    score_text_.setString("score : 0");
}

void ScoreBoard::update(int score) {
    high_score_ = std::max(high_score_, score);
    score_text_.setString("score : " + std::to_string(score));
    high_score_text_.setString("high score : " + std::to_string(high_score_));
}

void ScoreBoard::draw(sf::RenderWindow* app) {
    app->draw(score_text_);

    if (game_.isPlaying()) return;
    app->draw(game_over_text_);
    app->draw(high_score_text_);
}

void ScoreBoard::save() {
    std::ofstream write_file(SAVE_PATH);
    if (write_file.is_open()) {
        write_file << std::to_string(high_score_);
        write_file.close();
    }
}

void ScoreBoard::load() {
    std::ifstream open_file(SAVE_PATH);
    if (open_file.is_open()) {
        std::string line;
        while (getline(open_file, line)) {
            high_score_ = std::max(high_score_, stoi(line));
        }
        open_file.close();
    }
}
