#include "command.h"

#include "player.h"

void StartCommand::execute(Player* player) {
    player->initialize();
}

void LeftCommand::execute(Player* player) {
    player->moveToLeft();
}

void RightCommand::execute(Player* player) {
    player->moveToRight();
}