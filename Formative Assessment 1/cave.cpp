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

Cave::~Cave()
{
    delete (map[0][0]); // fixme: I don't think this deletes all Locations and arrays declared in the constructor...
    delete[] map; // fixme: ...neither does this.
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

    for (int y = 0; y < 8; y++)
    { // for all rows
        for (int x = 0; x < 8; x++) // for all columns
            cout << map[x][y] -> show(); // output whatever we find there

        cout << "  "; // list the things at this location
        if (y <  (int) thingsWithTom -> size())
            cout << (*thingsWithTom)[y] -> getName();

        cout << endl;
    }

    cout << endl;
}
