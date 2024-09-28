#ifndef THROW_H
#define THROW_H

#include <string>
#include <tuple>
#include "cave.h"
#include "thing.h"

class Throw
{
public:
    bool triggersOn(const std::string& command) const;
    void fire(Cave& cave, const std::string& command);

private:
    std::tuple<std::string, std::string> parseCommand(const std::string& command);
    bool movePosition(int& x, int& y, const std::string& direction);
};

#endif // THROW_H
