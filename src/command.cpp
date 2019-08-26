#include "command.h"

void StartCommand::execute(int* x, int* y, float* dy) {
    *x = 100;
    *y = 0;
    *dy = 0;
}

void LeftCommand::execute(int* x) {
    *x -= 3;
}

void RightCommand::execute(int* x) {
    *x += 3;
}