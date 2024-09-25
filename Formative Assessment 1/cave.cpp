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

// width and height of the cave
Cave::Cave(int w, int h) : width(w), height(h)
{
    // remove code to check wether cave size is standard(8×8)

    if ( width < 5 || height < 5)
        throw new logic_error("cave too small for tom.");

    // dynamically allocate the 2D array of Location
    // pointers based on the width and height
    map = new Location**[width];

    for (int x = 0; x < width; x++)
    {
        Location** column = new Location*[height];
        map[x] = column;
        for (int y = 0; y < height; y++)
            column[y] = new Location();
    }

    // add rocks around the edges
    for (int x = 0; x < width; x++)
    {
        for (int y = 0; y < height; y++)
        {
            if ( x == 0 || y == 0 || x == width - 1 || y == height - 1 )
                map[x][y] -> add( new Rock() );
        }
    }
    tom = new Tom();
    // add tom to the middle of the map
    tom -> setLocation( this, width/2,height/2);
}

// copy constructor (deep copy)
Cave::Cave(const Cave& other) : width(other.width), height(other.height)
{
    // deep copy Tom
    tom = new Tom(*other.tom);

    // deep copy map
    map = new Location**[width];
    for (int x = 0; x < width; x++)
    {
        map[x] = new Location*[height];
        for (int y = 0; y < height; y++)
        {
            // deep copy each Location
            map[x][y] = new Location(*other.map[x][y]);
        }
    }
}

// assigment operator (deep copy)
Cave& Cave::operator=(const Cave& other)
{
    //self-assigment check
    if (this == &other)
        return *this;

    // release current resources
    delete tom;
    for (int x = 0; x < width; x++)
    {
        for (int y = 0; y < height; y++)
        {
            delete map[x][y];
        }
        delete[] map[x];
    }
    delete[] map;

    // copy dimensions
    width = other.width;
    height = other.height;

    // deep copy Tom
    tom = new Tom(*other.tom);

    // deep copy map
    map = new Location**[width];
    for (int x = 0; x < width; x++)
    {
        map[x] = new Location*[height];
        for (int y = 0; y < height; y++)
        {
            // deep copy each Location
            map[x][y] = new Location(*other.map[x][y]);
        }
    }

    return *this;
}

Cave::~Cave()
{
    // release the Tom object
    delete tom;

    // delete all dynamically allocated Locations
    for (int x = 0; x < width; x++)
    {
        for (int y = 0; y < height; y++)
        {
            // delete each Location
            delete map[x][y];
        }
        // delete each column
        delete[] map[x];
    }
    // delete the top-level array
    delete[] map;
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
    // for all rows
    for (int y = 0; y < height; y++)
    {
        // for all columns
        for (int x = 0; x < width; x++)
            // output whatever we find there
            cout << map[x][y]->show();

        // list the things at this location
        cout << "  ";
        if (y < (int)thingsWithTom->size())
            cout << (*thingsWithTom)[y]->getName();

        cout << endl;
    }

    cout << endl;
}
