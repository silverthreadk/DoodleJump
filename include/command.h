#ifndef COMMAND_H_
#define COMMAND_H_

class Command {
 public:
    virtual ~Command(){}
    virtual void execute(int* x) = 0;
};

class LeftCommand : public Command {
 public:
    virtual void execute(int* x);
};

class RightCommand : public Command {
 public:
    virtual void execute(int* x);
};

#endif  // COMMAND_H_