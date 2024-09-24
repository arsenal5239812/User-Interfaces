#ifndef MUSHROOM_H
#define MUSHROOM_H

#include "thing.h"

// a small glowing mushroom on the ground, found wherever adventurers wander. Can be picked up.
class Mushroom : public Thing
{

    string getName()
    {
        return "mushroom";
    }
};

#endif // MUSHROOM_H
