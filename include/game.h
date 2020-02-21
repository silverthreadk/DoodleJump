#ifndef GAME_H_
#define GAME_H_

#include <SFML/Graphics.hpp>

class Background;
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
    void gameOver() { state_ = GAME_OVER; }
    bool isPlaying() const { return state_ == PLAYING; }

 private:
    void loadResource();
    void createPlatform();
    void createCoin();
    void handleInput();
    void layout();
    void draw();
    void adjustDifficultyLevel();

    sf::RenderWindow app_;
    GameState state_;
    Background* background_;
    Landscape* landscape_;
    Player* player_;
    ScoreBoard* score_board_;
    LifeBoard* life_board_;
    InputHandler* input_handler_;
    int difficulty_level_;
};

#endif  // GAME_H_
