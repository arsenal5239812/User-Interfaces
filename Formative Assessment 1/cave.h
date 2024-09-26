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
    // delete default constructor to avoid accidentally
    // creating invalid caves
    Cave() = delete;
    Cave(int width, int height);
    ~Cave();

    // copy constructor
    Cave(const Cave& other);

    // assignment operator
    Cave& operator=(const Cave& other);

    Location*** getMap() {return map;}
    void command (string s);
    void show();
    Tom *getTom() {return tom;}
    int getWidth() {return width;}
    int getHeight() {return height;}

    // add declaration for throwObject function
    // function to handle throwing objects
    void throwObject(string object, string direction);
private:
    int width, height;
    Tom *tom;
    Location*** map;
};

#endif // CAVE_H
