#ifndef GAME_H_
#define GAME_H_

#include <memory>
#include <SFML/Graphics.hpp>

class ResourceManager;
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
    void createPlatform();
    void createCoin();
    void handleInput();
    void layout();
    void draw();
    void adjustDifficultyLevel();

    sf::RenderWindow app_;
    GameState state_;
    std::unique_ptr<ResourceManager> resource_manager_;
    std::unique_ptr<Background> background_;
    std::unique_ptr<Landscape> landscape_;
    std::unique_ptr<Player> player_;
    std::unique_ptr<ScoreBoard> score_board_;
    std::unique_ptr<LifeBoard> life_board_;
    std::unique_ptr<InputHandler> input_handler_;
    int difficulty_level_;
};

#endif  // GAME_H_
