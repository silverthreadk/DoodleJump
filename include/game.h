#ifndef GAME_H_
#define GAME_H_

#include <SFML/Graphics.hpp>

class Landscape;
class Player;
class ScoreBoard;
class LifeBoard;
class InputHandler;

class Game {
 public:
    enum GameState { PLAYING, GAME_OVER };

    Game();
    ~Game();
    void initialize();
    void run();
    void close();
    bool isPlaying() const { return state_ == PLAYING; }
    void gameOver() { state_ = GAME_OVER; }

 private:
    void loadResource();
    void createPlatform();
    void createCoin();
    void handleInput();
    void layout();
    void draw();
    void adjustDifficultyLevel();

    sf::RenderWindow app_;

    sf::Sprite background_sprite_;

    GameState state_;
    Landscape* landscape_;
    Player* player_;
    ScoreBoard* score_board_;
    LifeBoard* life_board_;
    InputHandler* input_handler_;
    int difficulty_level_;
};

#endif  // GAME_H_
