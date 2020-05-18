#include "command.h"

#include "entity/player.h"

void StartCommand::execute(Player* player) {
    player->restart();
}

void CloseCommand::execute(Player* player) {
    player->close();
}

void LeftCommand::execute(Player* player) {
    player->moveToLeft();
}

void RightCommand::execute(Player* player) {
    player->moveToRight();
}
