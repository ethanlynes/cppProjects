#include <iostream>
#include <vector>
#include <cstring>
#include "room.h"
#include "items.h"

using namespace std;

/*
Name: Ethan Lynes
Date:
Program:

*/

//function declarations
void createRooms();
void listCommands();
bool processCommand(char command[10]);
bool isCommand(char command[10]);
void goRoom(char command[10]);

char SOUTH[6] = "south";
char NORTH[6] = "north";
char EAST[5] = "east";
char WEST[5] = "west";

char validCommands[][10] = {
    "go", "quit", "help", "inventory", "get", "drop"
};

int main() {
  
  createRooms();

  cout << "Type 'help' for a list of commands." << endl;
  
  bool finished = false;
  while (!finished) {
    
    char command[10];
    cin.get(command,10);
    cin.get();
    
    finished = processCommand(command);
  }
  
  return 0;
}


void listCommands() {
  cout << "Commands: ";
  for (int i = 0; i < 6; i++) {
    cout << validCommands[i] << ", ";
  }
  cout << endl << endl;
}


bool processCommand(char command[10]) {

  bool wantToQuit = false;
  
  if (!isCommand(command)) {
    cout << "That is not a valid command!" << endl;
    return false;
  }
  
  if (!strcmp(command,"help")) {
    listCommands();
  } else if (!strcmp(command,"quit")) {
    wantToQuit = true;
  }
  return wantToQuit;
}


bool isCommand(char command[10]) {
  for (int i = 0; i < 6; i++) {
    if (!strcmp(command,validCommands[i])) {
      return true;
    }
  }
  return false;
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


void goRoom(char command[10]) {

}
