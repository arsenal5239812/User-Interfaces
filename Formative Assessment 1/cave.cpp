#include <stdexcept>
#include <string>
#include <iostream>
#include <vector>
#include <string>

#include "cave.h"
#include "rock.h"
#include "thing.h"
#include "location.h"
#include "move.h"
#include "place.h"

using namespace std;

Cave::Cave(int w, int h) : width(w), height(h) // width and height of the cave
{

    if ( width < 5 || height < 5)
        throw new logic_error("cave too small for tom.");

    map = new Location**[width];

    for (int x = 0; x < width; x++)
    {
        Location** column = new Location*[height];
        map[x] = column;
        for (int y = 0; y < height; y++)
            column[y] = new Location();
    }

    // create some rocks
    for (int x = 0; x < width; x++)
        for (int y = 0; y < height; y++)
            if ( x == 0 || y == 0 || x == width - 1 || y == height - 1 )
                 map[x][y] -> add( new Rock() );

    tom = new Tom();
    // add tom to the middle of the map
    tom -> setLocation( this, width/2,height/2);
}

Cave::~Cave()
{
    for (int x = 0; x < width; x++)
    {
        for (int y = 0; y < height; y++)
        {
            delete map[x][y];
        }
        delete [] map[x];
    }
    delete [] map;
}

Cave::Cave(const Cave &other)
{
    copyFrom(other);
}

Cave& Cave::operator=(const Cave &other)
{
    if (this != &other)
    {
        for (int x = 0; x < width; x++)
        {
            for (int y = 0; y < height; y++)
            {
                delete map[x][y];
            }
            delete [] map[x];
        }
        delete [] map;

        // copy new object
        copyFrom(other);
    }
    return *this;
}

void Cave::command (string userCommand)
{
    if (Move().triggersOn(userCommand))
        Move().fire(*this, userCommand);
    else if (Place().triggersOn(userCommand))
        Place().fire(*this, userCommand);
    else
        cerr << "tom doesn't know how to "+userCommand << endl;;
}

void Cave::show()
{
    vector<Thing*>* thingsWithTom = map[tom -> getX()][tom -> getY()] -> getThings();

    for (int y = 0; y < height; y++)
    { // for all rows
        for (int x = 0; x < width; x++) // for all columns
            cout << map[x][y] -> show(); // output whatever we find there

        cout << "  "; // list the things at this location
        if (y <  (int) thingsWithTom -> size())
            cout << (*thingsWithTom)[y] -> getName();

        cout << endl;
    }

    cout << endl;
}

void Cave::copyFrom(const Cave &other)
{
    this->width = other.width;
    this->height = other.height;
    this->map = new Location**[this->width];

    for (int x = 0; x < width; x++)
    {
        Location** column = new Location*[height];
        map[x] = column;
        for (int y = 0; y < height; y++)
        {
            column[y] = new Location();
        }
    }

    for (int x = 0; x < width; x++)
        for (int y = 0; y < height; y++)
        {
            vector<Thing*>* thingsWit = other.map[x][y] -> getThings();
            for (int i = 0; i < (int)thingsWit->size(); i++)
            {
                string name = (*thingsWit)[i] -> getName();
                if (name == "mushroom")
                {
                    this->map[x][y] -> add(new Mushroom);
                }
                else if (name == "rock")
                {
                    this->map[x][y] -> add(new Rock);
                }
                else if (name == "coin")
                {
                    this->map[x][y] -> add(new Coin);
                }
            }
        }

    tom = new Tom(*other.tom);
    tom->setLocation(this, other.tom->getX(), other.tom->getY());
}
