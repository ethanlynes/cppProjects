#include <iostream>
#include <cstring>
#include "items.h"

using namespace std;

/*
Name: Ethan Lynes
Date:
Program: Adventure game
File: Item class file
*/

// constructor, copies given name into it's member
Item::Item(char newname[20]) {
    strcpy(name,newname);
}
