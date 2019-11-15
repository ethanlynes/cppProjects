#include <iostream>
#include <cstring>
#include "room.h"

using namespace std;

Room::Room(char newdescription[80]) {
  strcpy(description,newdescription);
}

