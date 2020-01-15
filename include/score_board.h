#ifndef SCORE_BOARD_H_
#define SCORE_BOARD_H_

#include <SFML/Graphics.hpp>

class Player;

class ScoreBoard {
 public:
    ScoreBoard();
    ~ScoreBoard();
    void initialize();
    void update(Player* player);
    void draw(sf::RenderWindow* app);
    void save();

 private:
    void load();

    sf::Text score_text_;
    sf::Text high_score_text_;
    sf::Text game_over_text_;
    int high_score_;
};

#endif  // SCORE_BOARD_H_
