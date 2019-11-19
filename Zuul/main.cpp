#include <iostream>
#include <vector>
#include <cstring>
#include "room.h"
#include "items.h"

using namespace std;

void createRooms();

char SOUTH[6] = "south";
char NORTH[6] = "north";
char EAST[5] = "east";
char WEST[5] = "west";

int main() {
  
  createRooms();
  return 0;
}

void createRooms() {

  vector<Room*>* rooms = new vector<Room*>;

  
  
  char office_d[] = "You are in the office.";
  char office_n[] = "The Office.";
  
  Room* office = new Room(office_d,office_n);
  
  rooms->push_back(office);

  char lobby_d[] = "You are in the lobby.";
  char lobby_n[] = "The lobby.";
  
  Room* lobby = new Room(lobby_d,lobby_n);
  
  rooms->push_back(lobby);
  
  cout << (*rooms)[0]->name << endl;

  office->setExit(EAST,lobby);
  lobby->setExit(WEST,office);
}
