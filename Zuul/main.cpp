#include <iostream>
#include <vector>
#include <cstring>
#include "room.h"
#include "items.h"

using namespace std;

int main() {
  vector<Room*>* rooms = new vector<Room*>;

  Room* office = new Room("You are in the office.");
  strcpy(office->name,"The Office.");

  cout << office->name << endl;
  
  rooms->push_back(office);

  return 0;
}
