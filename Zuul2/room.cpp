#include <iostream>
#include <cstring>
#include <map>
#include "room.h"

using namespace std;

/*
Name: Ethan Lynes
Date:
Program: Adventure game
File: Room class file
*/

// constructor, copies parameters to members
Room::Room(char newdescription[80], char newname[80]) {
  strcpy(description,newdescription);
  strcpy(name,newname);
}

// sets exits to its map based on parameters
void Room::setExit(char direction[6], Room* neighbor) {
  room_exits.insert(pair<char*,Room*>(direction,neighbor));
}

// adds items to its vector
void Room::setItem(Item* item) {
    items.push_back(item);
}

// method for checking if an exit exists
bool Room::checkExit(char direction[20]) {
    map<char*, Room*>::iterator itr; 
    bool isExit = false;
    for (itr = room_exits.begin(); itr != room_exits.end(); ++itr) { 
        if (!strcmp(direction,itr->first)) {
            isExit = true;
        }
    }
    if (!isExit) {
        cout << "Exit doesn't exist" << endl;
    }
    return isExit;
}

// method for changing currentroom
void Room::goExit(char direction[20], Room* &currentRoom) {
    map<char*, Room*>::iterator itr; 
    for (itr = room_exits.begin(); itr != room_exits.end(); ++itr) { 
        if (!strcmp(direction,itr->first)) {
            currentRoom = itr->second;
        }
    }
}

// method for displaying all available exits in a room
void Room::listExits() {
    map<char*, Room*>::iterator itr;
    for (itr = room_exits.begin(); itr != room_exits.end(); ++itr) {
        cout << "'Go " << itr->first << "' to go to "
             << itr->second->name << endl;
    }
}
