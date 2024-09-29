#ifndef PLACE_H
#define PLACE_H

#include "coin.h"
#include "command.h"
#include "mushroom.h"
#include "rock.h"
#include "bomb.h"
#include <iostream>

using namespace std;

class Place : public Command
{
public:
    Place() : Command("place") {};
    void fire(Cave& c, string userCommand);
};
#endif // PLACE_H
