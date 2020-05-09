#include "input_handler.h"

#include <SFML/Graphics.hpp>

#include "command.h"

InputHandler::InputHandler() : key_enter_(std::unique_ptr<Command>(new StartCommand())),
    key_esc_(std::unique_ptr<Command>(new CloseCommand())),
    key_left_(std::unique_ptr<Command>(new LeftCommand())),
    key_right_(std::unique_ptr<Command>(new RightCommand())) {
}

InputHandler::~InputHandler() {
}

Command* InputHandler::handleInput() const {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) return key_enter_.get();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) return key_esc_.get();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) return key_left_.get();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) return key_right_.get();
    return nullptr;
}
