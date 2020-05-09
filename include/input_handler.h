#ifndef INPUT_HANDLER_H_
#define INPUT_HANDLER_H_

#include <memory>

class Command;

class InputHandler {
 public:
    InputHandler();
    ~InputHandler();
    Command* handleInput() const;

 private:
    std::unique_ptr<Command> key_enter_;
    std::unique_ptr<Command> key_esc_;
    std::unique_ptr<Command> key_left_;
    std::unique_ptr<Command> key_right_;
};
#endif  // INPUT_HANDLER_H_
