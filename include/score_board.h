#ifndef SCORE_BOARD_H_
#define SCORE_BOARD_H_

#include <SFML/Graphics.hpp>

class Landscape;
class Player;
class InputHandler;

class ScoreBoard {
 public:
    ScoreBoard(sf::RenderWindow* app, sf::Font* font);

    ~ScoreBoard();

    void update(int score);

    void draw(sf::RenderWindow* app, const bool is_game_over);

 private:
    sf::Text score_text_;
    sf::Text high_score_text_;
    sf::Text game_over_text_;

    int high_score_;
};

#endif  // SCORE_BOARD_H_
