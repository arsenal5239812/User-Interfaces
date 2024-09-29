#include "explode.h"
#include "bomb.h"
#include "rock.h"
#include <iostream>
#include <set>

void Explode::fire(Cave& c, std::string userCommand)
{
    int x = c.getTom()->getX();
    int y = c.getTom()->getY();
    std::set<std::pair<int, int>> exploded;
    explodeLocation(c, x, y, exploded);
}

void Explode::explodeLocation(Cave& c, int x, int y, std::set<std::pair<int, int>>& exploded)
{
    // Avoid duplicate explosions
    if (exploded.find({x, y}) != exploded.end())
        return;

    Location* loc = c.getMap()[x][y];
    exploded.insert({x, y});

    // Remove all Things except Tom
    std::vector<Thing *> *things = loc->getThings();
    for (auto it = things->begin(); it != things->end();)
    {
        if (dynamic_cast<Tom*>(*it) == nullptr)
        {
            delete *it;
            it = things->erase(it);
        }
        else
        {
            ++it;
        }
    }

    // Check for adjacent bombs and explode them
    int dx[] = {0, 0, -1, 1};
    int dy[] = {-1, 1, 0, 0};
    for (int i = 0; i < 4; ++i)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && ny >= 0 && nx < c.getWidth() && ny < c.getHeight())
        {
            Location* adjLoc = c.getMap()[nx][ny];
            for (Thing* t : *adjLoc->getThings())
            {
                if (dynamic_cast<Bomb*>(t) != nullptr)
                {
                    explodeLocation(c, nx, ny, exploded);
                    break;
                }
            }
        }
    }
}
