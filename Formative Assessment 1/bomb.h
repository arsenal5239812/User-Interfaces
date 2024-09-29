#ifndef BOMB_H
#define BOMB_H

#include "thing.h"
#include <string>

// a bomb does not block tom and can be placed
class Bomb : public Thing
{
public:
    Bomb() {}
    ~Bomb() {}
    std::string getName()
    {
        return "bomb";
    }
};

#endif // BOMB_H
