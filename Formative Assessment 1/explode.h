#ifndef EXPLODE_H
#define EXPLODE_H

#include "command.h"
#include "cave.h"
#include <set>

class Explode : public Command
{
public:
    Explode() : Command("explode") {}
    void fire(Cave& c, std::string userCommand);

private:
    void explodeLocation(Cave& c, int x, int y, std::set<std::pair<int, int>>& exploded);
};

#endif // EXPLODE_H
