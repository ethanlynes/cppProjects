#include <iostream>
#include <map>
#include <vector>
#include "items.h"

using namespace std;

/*
Name: Ethan Lynes
Date:
Program: Adventure game
File: Room class header
*/

// Room class construction
class Room {
 public:
 // vars, sets up exits and vector of items for each room
  char name[20];
  char description[80];
  map<char*, Room*> room_exits;
  vector<Item*> items;
  
  // functions
  Room(char newdescription[80], char newname[20]);
  void setExit(char direction[6], Room* neighbor);
  void setItem(Item* item);
  bool checkExit(char direction[20]);
  void goExit(char direction[20], Room* &currentRoom);
  void listExits();
};
