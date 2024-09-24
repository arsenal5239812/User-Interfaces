#include "place.h"
#include "thing.h"

void Place::fire(Cave& c, string userCommand)
{
    string s = tail(userCommand);
    Location* loc = c.getMap()[c.getTom()->getX()][c.getTom()->getY()];

    if (s.compare("coin")==0)
        loc ->add(new Coin());
    else if (s.compare("mushroom")==0)
        loc ->add(new Mushroom());
    else
        cerr << "I don't know how to place a " << userCommand << endl;
}
