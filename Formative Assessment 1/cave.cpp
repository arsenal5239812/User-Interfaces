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
    // remove code to check wether cave size is standard(8×8)

    if ( width < 5 || height < 5)
        throw new logic_error("cave too small for tom.");

    // dynamically allocate the 2D array of Location pointers based on the width and height
    map = new Location**[width];

    for (int x = 0; x < width; x++) {
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
    delete tom;

    // Delete all dynamically allocated Locations
    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            delete map[x][y]; // delete each Location
        }
        delete[] map[x]; // delete each column
    }
    delete[] map; // delete the top-level array
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

    for (int y = 0; y < height; y++) // for all rows
    {
        for (int x = 0; x < width; x++) // for all columns
            cout << map[x][y]->show(); // output whatever we find there

        cout << "  "; // list the things at this location
        if (y < (int)thingsWithTom->size())
            cout << (*thingsWithTom)[y]->getName();

        cout << endl;
    }

    cout << endl;
}
