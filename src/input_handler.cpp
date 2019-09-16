#include "input_handler.h"
#include "command.h"

#include <SFML/Graphics.hpp>

InputHandler::InputHandler() {
    key_enter_ = new StartCommand();
    key_left_ = new LeftCommand();
    key_right_ = new RightCommand();
}

InputHandler::~InputHandler() {
}

Command* InputHandler::handleInput(bool game_over) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && game_over) return key_enter_;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !game_over) return key_left_;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && !game_over) return key_right_;
    return nullptr;
}
