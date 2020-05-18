#include "score_board.h"

#include <string>
#include <fstream>
#include <iostream>

#include "config.h"
#include "resource_holder.h"
#include "entity/player.h"

static void initilazeText(sf::Font* font, int font_size, sf::Text* text) {
    text->setFont(*font);
    text->setCharacterSize(font_size);
    text->setStyle(sf::Text::Bold);
    text->setColor(sf::Color::Black);
}

static void alignText(std::vector<sf::Text*>& text_list) {
    float text_height = 0;
    float max_width = 0;
    for (auto& text : text_list) {
        max_width = std::max(max_width, text->getLocalBounds().width);
        text_height += text->getLocalBounds().height;
    }

    float next_y = (kScreenHeight - text_height) / 2;
    for (auto& text : text_list) {
        text->setOrigin(max_width / 2.f, text->getLocalBounds().height / 2.f);
        text->setPosition(kScreenWidth / 2.f, next_y);
        next_y += text->getLocalBounds().height + 14;
    }
}

ScoreBoard::ScoreBoard() : high_score_(0) {
    sf::Font* font = &FontHolder::getInstance()->get(Fonts::MAIN);

    initilazeText(font, 25, &game_over_text_);
    game_over_text_.setString("Press Enter to Continue");

    initilazeText(font, 20, &high_score_text_);
    high_score_text_.setString("high score : ");

    std::vector<sf::Text*> text_list;
    text_list.push_back(&game_over_text_);
    text_list.push_back(&high_score_text_);
    alignText(text_list);

    initilazeText(font, 20, &score_text_);
    score_text_.setPosition(10, 10);
    initialize();
    load();
}

ScoreBoard::~ScoreBoard() {
}

void ScoreBoard::initialize() {
    score_text_.setString("score : 0");
    high_score_text_.setColor(sf::Color::Transparent);
    game_over_text_.setColor(sf::Color::Transparent);
}

void ScoreBoard::update(Player* player) {
    high_score_ = std::max(high_score_, player->getScore());
    score_text_.setString("score : " + std::to_string(player->getScore()));

    if (player->getLives() > 0) return;

    high_score_text_.setString("high score : " + std::to_string(high_score_));
    high_score_text_.setColor(sf::Color::Black);
    game_over_text_.setColor(sf::Color::Black);
}

void ScoreBoard::draw(sf::RenderWindow* app) {
    app->draw(score_text_);
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
