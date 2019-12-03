 
#ifndef ITEMS_H
#define ITEMS_H
#include <iostream>

using namespace std;

/*
Name: Ethan Lynes
Date:
Program: Adventure game
File: Item class header
*/

// basic item class with member 'name'
class Item {
    public:
        char name[20];
        
        Item(char newname[20]);
};

#endif
