#include <iostream>
#include <map>
using namespace std;

class Room {
 public:
  char name[20];
  char description[80];
  map<char*, Room*> room_exits;

  Room(char newdescription[80], char newname[80]);
  void setExit(char direction[6], Room* neighbor);
};
