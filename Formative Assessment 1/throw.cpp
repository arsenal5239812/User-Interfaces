#include "throw.h"
#include "tokenizer.h" // used to extract various parts from commands
#include "mushroom.h"
#include "rock.h"
#include "coin.h"
#include <iostream>

bool Throw::triggersOn(const std::string& command) const
{
    return command.find("throw") == 0;
}

void Throw::fire(Cave& cave, const std::string& command)
{
    // disassemble using standard tuples
    std::tuple<std::string, std::string> parsedCommand = parseCommand(command);
    std::string object = std::get<0>(parsedCommand);
    std::string direction = std::get<1>(parsedCommand);

    Tom* tom = cave.getTom();
    int x = tom->getX();
    int y = tom->getY();

    if (object.empty() || direction.empty()) {
        std::cerr << "Invalid throw command format" << std::endl;
        return;
    }

    // move to the specified direction
    if (!movePosition(x, y, direction)) {
        std::cerr << "Invalid direction" << std::endl;
        return;
    }

    // check if the target position is obstructed
    Location* targetLocation = cave.getMap()[x][y];
    if (targetLocation->isBlocking()) {
        std::cerr << "Cannot throw object to a blocking location" << std::endl;
        return;
    }

    // throw out items
    if (object == "mushroom") {
        targetLocation->add(new Mushroom());
    } else if (object == "rock") {
        targetLocation->add(new Rock());
    } else if (object == "coin") {
        targetLocation->add(new Coin());
    } else {
        std::cerr << "Unknown object: " << object << std::endl;
    }
}

std::tuple<std::string, std::string> Throw::parseCommand(const std::string& command)
{
    Tokenizer tokenizer(command);
    tokenizer.next(); // skip 'throw'
    std::string object = tokenizer.next();
    std::string direction = tokenizer.next();

    return std::make_tuple(object, direction);
}

bool Throw::movePosition(int& x, int& y, const std::string& direction) {
    if (direction == "north") {
        y--;
    } else if (direction == "south") {
        y++;
    } else if (direction == "east") {
        x++;
    } else if (direction == "west") {
        x--;
    } else {
        return false;
    }
    return true;
}

