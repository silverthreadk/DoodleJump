#include "input_handler.h"
#include "command.h"

#include <SFML/Graphics.hpp>

InputHandler::InputHandler() {
    key_enter_ = new StartCommand();
    key_left_ = new LeftCommand();
    key_right_ = new RightCommand();
}

InputHandler::~InputHandler() {
    delete key_enter_;
    delete key_left_;
    delete key_right_;
}

Command* InputHandler::handleInput() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) return key_enter_;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) return key_left_;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) return key_right_;
    return nullptr;
}
