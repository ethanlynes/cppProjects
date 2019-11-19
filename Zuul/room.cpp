#include <iostream>
#include <cstring>
#include <map>
#include "room.h"

using namespace std;

Room::Room(char newdescription[80], char newname[80]) {
  strcpy(description,newdescription);
  strcpy(name,newname);
  //room_exits = new map<char*, Room*>;
}

void Room::setExit(char direction[6], Room* neighbor) {
  room_exits.insert(pair<char*,Room*>(direction,neighbor));
}
