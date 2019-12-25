#ifndef COMMAND_H_
#define COMMAND_H_

class Player;

class Command {
 public:
    virtual ~Command() {}
    virtual void execute(Player* player) = 0;
};

class StartCommand : public Command {
 public:
    void execute(Player* player);
};

class CloseCommand : public Command {
 public:
    void execute(Player* player);
};

class LeftCommand : public Command {
 public:
    void execute(Player* player);
};

class RightCommand : public Command {
 public:
    void execute(Player* player);
};

#endif  // COMMAND_H_
