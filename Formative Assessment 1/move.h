#ifndef MOVE_H
#define MOVE_H

#include "cave.h"
#include "command.h"

#include <string>
#include <iostream>
#include <string>

using namespace std;


// a command to move tom around the cave.
class Move : public Command
{
public:
    Move() : Command("move") {};
    void fire(Cave& c, string userCommand);
};

#endif // MOVE_H
