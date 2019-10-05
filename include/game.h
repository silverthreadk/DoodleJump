#ifndef GAME_H_
#define GAME_H_

#include <SFML/Graphics.hpp>

class Landscape;
class Player;
class InputHandler;

class Game {
 public:
    enum GameState { PLAYING, GAME_OVER };

    Game();

    ~Game();

    void gameLoop();

 private:
    void draw();

    const int screen_width_;
    const int screen_height_;

    sf::RenderWindow app;
    sf::Texture background_texture_;
    sf::Texture platform_texture_; 
    sf::Texture doodle_texture_;
    sf::Font font_;
    sf::Text game_over_text_;
    sf::Text score_text_;

    sf::Sprite background_sprite_;
    sf::Sprite plat_sprite_;
    sf::Sprite doodle_sprite_;

    GameState state_;
    Landscape* landscape_;
    Player* player_;
    InputHandler* input_handler_;
};

#endif  // GAME_H_
