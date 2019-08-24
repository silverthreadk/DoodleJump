#include "command.h"

void LeftCommand::execute(int* x) {
    *x -= 3;
}

void RightCommand::execute(int* x) {
    *x += 3;
}