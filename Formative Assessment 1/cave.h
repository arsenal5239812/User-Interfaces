#ifndef CAVE_H
#define CAVE_H

#include "location.h"
#include "tom.h"

using namespace std;

class Tom; // forward reference

// A cave which contains everything, including tom.
class Cave
{
public:
    // Copy constructor
    Cave(const Cave &other);
    // Copy assignment operator
    Cave& operator=(const Cave &other);

    Cave(){};
    Cave(int width, int height);
    ~Cave();
    Location*** getMap() {return map;}
    void command (string s);
    void show();
    Tom *getTom() {return tom;}
    int getWidth() {return width;}
    int getHeight() {return height;}
private:
    // Helper function for deep copy
    void copyFrom(const Cave &other);
    int width, height;
    Tom *tom;
    Location*** map;
};

#endif // CAVE_H
