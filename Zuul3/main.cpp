#include <iostream>
#include <vector>
#include <cstring>
#include "room.h"
#include "items.h"

using namespace std;

/*
Name: Ethan Lynes
Date:
Program: Adventure game
File: Main Zuul file
*/

// function declarations
void listCommands(char validCommands[][10]);
bool processCommand(char word1[10], char word2[20], char validCommands[][10], Room* &currentRoom, vector<Item*> &inventory);
bool isCommand(char command[10], char validCommands[][10]);
void goRoom(char direction[20], Room* &currentRoom);
bool hasSecondWord(char word2[20]);
void listInventory(vector<Item*> inventory);
void getItem(char itemname[20], Room* &currentRoom, vector<Item*> &inventory);
void dropItem(char itemname[20], Room* &currentRoom, vector<Item*> &inventory);
void describeRoom(Room* currentRoom);


int main() {
  
  // vars
  char SOUTH[6] = "south";
  char NORTH[6] = "north";
  char EAST[5] = "east";
  char WEST[5] = "west";
  char validCommands[][10] = {
    "go", "quit", "help", "inventory", "get", "drop", "room", "list"
  };
  vector<Item*> inventory;
  
  
  // rooms
  Room* currentRoom;
  
  char entrance_d[] = "You are at the entrance of the supermarket.";
  char entrance_n[] = "The Entrance.";
  Room* entrance = new Room(entrance_d,entrance_n);

  char center_d[] = "You are at the center of the supermarket.";
  char center_n[] = "The center.";
  Room* center = new Room(center_d,center_n);
  
  char checkout_d[] = "You are at checkout.";
  char checkout_n[] = "checkout";
  Room* checkout = new Room(checkout_d,checkout_n);

  char starbucks_d[] = "You are in Starbucks.";
  char starbucks_n[] = "Starbucks.";
  Room* starbucks = new Room(starbucks_d,starbucks_n);

  char aisle1_d[] = "You are in aisle 1.";
  char aisle1_n[] = "aisle 1.";
  Room* aisle1 = new Room(aisle1_d,aisle1_n);

  char aisle2_d[] = "You are in aisle 2.";
  char aisle2_n[] = "aisle 2.";
  Room* aisle2 = new Room(aisle2_d,aisle2_n);

  char aisle3_d[] = "You are in aisle 3.";
  char aisle3_n[] = "aisle 3.";
  Room* aisle3 = new Room(aisle3_d,aisle3_n);

  char aisle4_d[] = "You are in aisle 4.";
  char aisle4_n[] = "aisle 4.";
  Room* aisle4 = new Room(aisle4_d,aisle4_n);

  char aisle5_d[] = "You are in aisle 5.";
  char aisle5_n[] = "aisle 5.";
  Room* aisle5 = new Room(aisle5_d,aisle5_n);

  char chips_d[] = "You are in the chip aisle.";
  char chips_n[] = "chip aisle.";
  Room* chips = new Room(chips_d,chips_n);

  char bread_d[] = "You are in the bread aisle.";
  char bread_n[] = "bread aisle.";
  Room* bread = new Room(bread_d,bread_n);

  char drinks_d[] = "You are in the drinks aisle.";
  char drinks_n[] = "drinks aisle.";
  Room* drinks = new Room(drinks_d,drinks_n);

  char condiments_d[] = "You are in the condiment aisle.";
  char condiments_n[] = "condiments aisle.";
  Room* condiments = new Room(condiments_d,condiments_n);

  char dairy_d[] = "You are in the dairy aisle.";
  char dairy_n[] = "dairy aisle.";
  Room* dairy = new Room(dairy_d,dairy_n);

  char seafood_d[] = "You are in the seafood aisle.";
  char seafood_n[] = "seafood aisle.";
  Room* seafood = new Room(seafood_d,seafood_n);

  char meat_d[] = "You are in the meat aisle.";
  char meat_n[] = "meat aisle.";
  Room* meat = new Room(meat_d,meat_n);

  char fruit_d[] = "You are in the fruit aisle.";
  char fruit_n[] = "fruit aisle.";
  Room* fruit = new Room(fruit_d,fruit_n);
  
  char frozen_d[] = "You are in the frozen aisle.";
  char frozen_n[] = "frozen aisle";
  Room* frozen = new Room(frozen_d,frozen_n);
  
  char vegg_d[] = "You are in the vegetable aisle.";
  char vegg_n[] = "vegetable aisle.";
  Room* vegg = new Room(vegg_d,vegg_n);
  
  // set exits
  entrance->setExit(NORTH,center);
  
  center->setExit(EAST,checkout);
  center->setExit(WEST,starbucks);
  center->setExit(NORTH,aisle1);
  center->setExit(SOUTH,entrance);
  checkout->setExit(WEST,center);
  starbucks->setExit(EAST,center);
  
  aisle1->setExit(SOUTH,center);
  aisle1->setExit(NORTH,aisle2);
  aisle1->setExit(EAST,bread);
  aisle1->setExit(WEST,chips);
  chips->setExit(EAST,aisle1);
  bread->setExit(WEST,aisle1);
  
  aisle2->setExit(SOUTH,aisle1);
  aisle2->setExit(NORTH,aisle3);
  aisle2->setExit(EAST,condiments);
  aisle2->setExit(WEST,drinks);
  condiments->setExit(WEST,aisle2);
  drinks->setExit(EAST,aisle2);
  
  aisle3->setExit(SOUTH,aisle2);
  aisle3->setExit(NORTH,aisle4);
  aisle3->setExit(EAST,seafood);
  aisle3->setExit(WEST,dairy);
  dairy->setExit(EAST,aisle3);
  seafood->setExit(WEST,aisle3);
  
  aisle4->setExit(SOUTH,aisle3);
  aisle4->setExit(NORTH,aisle5);
  aisle4->setExit(EAST,fruit);
  aisle4->setExit(WEST,meat);
  meat->setExit(EAST,aisle4);
  fruit->setExit(WEST,aisle4);
  
  aisle5->setExit(SOUTH,aisle4);
  aisle5->setExit(EAST,vegg);
  aisle5->setExit(WEST,frozen);
  frozen->setExit(EAST,aisle5);
  vegg->setExit(WEST,aisle5);
  
  currentRoom = entrance;

  
  // items
  char frappe_n[] = "frappe";
  Item* frappe = new Item(frappe_n);
  starbucks->setItem(frappe);

  char doritos_n[] = "doritos";
  Item* doritos = new Item(doritos_n);
  chips->setItem(doritos);

  char whitebread_n[] = "bread";
  Item* whitebread = new Item(whitebread_n);
  bread->setItem(whitebread);

  char bagel_n[] = "bagel";
  Item* bagel = new Item(bagel_n);
  bread->setItem(bagel);

  char water_n[] = "water";
  Item* water = new Item(water_n);
  drinks->setItem(water);

  char soda_n[] = "soda";
  Item* soda = new Item(soda_n);
  drinks->setItem(soda);
  
  char cannedtuna_n[] = "tuna";
  Item* cannedtuna = new Item(cannedtuna_n);
  seafood->setItem(cannedtuna);

  char shrimp_n[] = "shrimp";
  Item* shrimp = new Item(shrimp_n);
  seafood->setItem(shrimp);

  char lobster_n[] = "lobster";
  Item* lobster = new Item(lobster_n);
  seafood->setItem(lobster);

  char steak_n[] = "steak";
  Item* steak = new Item(steak_n);
  meat->setItem(steak);

  char chicken_n[] = "chicken";
  Item* chicken = new Item(chicken_n);
  meat->setItem(chicken);
  
  char mayo_n[] = "mayo";
  Item* mayo = new Item(mayo_n);
  condiments->setItem(mayo);
  
  char relish_n[] = "relish";
  Item* relish = new Item(relish_n);
  condiments->setItem(relish);

  char ketchup_n[] = "ketchup";
  Item* ketchup = new Item(ketchup_n);
  condiments->setItem(ketchup);

  char mustard_n[] = "mustard";
  Item* mustard = new Item(mustard_n);
  condiments->setItem(mustard);

  char tomato_n[] = "tomato";
  Item* tomato = new Item(tomato_n);
  fruit->setItem(tomato);

  char apple_n[] = "apple";
  Item* apple = new Item(apple_n);
  fruit->setItem(apple);

  char pizza_n[] = "pizza";
  Item* pizza = new Item(pizza_n);
  frozen->setItem(pizza);
  
  char icecream_n[] = "icecream";
  Item* icecream = new Item(icecream_n);
  frozen->setItem(icecream);
  
  char onion_n[] = "onion";
  Item* onion = new Item(onion_n);
  vegg->setItem(onion);

  char lettuce_n[] = "lettuce";
  Item* lettuce = new Item(lettuce_n);
  vegg->setItem(lettuce);
  
  // start of program
  cout << "You are in a grocery store. Your job is to find all the items" << endl
       << "on your list and proceed to checkout" << endl
       << "Your list: mayo, relish, onion, tuna" << endl << endl;
  describeRoom(currentRoom);
  cout << "Type 'help' for a list of commands." << endl;
  
  bool finished = false;
  bool hasWon = false;
  while (!finished && !hasWon) {
    
    // takes input as a 'command'
    char command[40];
    cin.get(command,40);
    cin.get();
    
    // initializes word1 and word2 with a space (for comparison's sake)
    char word1[10] = " ";
    char word2[20] = " ";
    int wordCount = 1;
    
    // goes through input and adds to wordCount for every space
    int length = strlen(command);
    for (int i = 0; i < length; i++) {
      if (command[i] == ' ') {
	wordCount++;
      }
      //input filter
      command[i] = tolower(command[i]);
    }
    
    // if there are too many words then restart
    if (wordCount > 2) {
      cout << "Enter no more than 2 commands" << endl;
    } else {
      // else, the wordCount is below 3
      // separate the input into tokens by a space and
      // assign them to word1 and word2
      int count = 0;
      char *token = strtok(command," ");
      while (token) {
	count++;
	if (count == 1) {
	  strcpy(word1,token);
	} else if (count == 2) {
	  strcpy(word2,token);
	}
	token = strtok(NULL," ");
      }
      // finally, process the input
      // while loop will end if 'processCommand' evaluates to true
      // (if user either quits or the winning condition is met)
      finished = processCommand(word1,word2,validCommands,currentRoom,inventory);
      
      int size = inventory.size();
      int check = 0;
      
      if (currentRoom == checkout) {
	for (int i = 0; i < size; i++) {
	  if (!strcmp(inventory[i]->name,"mayo")) {
  	    check++;
 	  }
	  if (!strcmp(inventory[i]->name,"relish")) {
	    check++;
	  }
	  if (!strcmp(inventory[i]->name,"tuna")) {
	    check++;
	  }
	  if (!strcmp(inventory[i]->name,"onion")) {
	    check++;
	  }
	}
	if (check == 4 && size == 4) {
	  hasWon = true;
	}
      }
    }
    if (hasWon) {
      cout << "You successfully found everything on your shopping list!" << endl;
      cout << "You can now enjoy your freshly made tuna salad." << endl;
      cout << "Thank you for playing.";
    }
  }
  
  return 0;
}

// lists the commands available
// from the validCommands array
void listCommands(char validCommands[][10]) {
  cout << "Commands: ";
  for (int i = 0; i < 8; i++) {// goes through array
    if (i == 7) {// print last element without a comma
      cout << validCommands[i];
    } else {// print elements before last with a comma
      cout << validCommands[i] << ", ";
    }
  }
  cout << endl << endl;
}

// processes all the commands entered
// executes different code depending user input
// only returns true if the user enters 'quit'
bool processCommand(char word1[10], char word2[20], char validCommands[][10], Room* &currentRoom, vector<Item*> &inventory) {
  
  bool wantToQuit = false;
  
  // first check if the input is valid, if not return false (exits function)
  if (!isCommand(word1,validCommands)) {
    cout << "That is not a valid command!" << endl;
    return false;
  }
  
  // calls on a function for each command
  if (!strcmp(word1,"help")) {
    listCommands(validCommands);
  } else if (!strcmp(word1,"go")) {
    goRoom(word2,currentRoom);
  } else if (!strcmp(word1,"quit")) {
    if (hasSecondWord(word2)) {
      cout << "Quit what?" << endl;
    } else {
      cout << "Quitting.." << endl;
      wantToQuit = true;
    }
  } else if (!strcmp(word1,"room")) {
    describeRoom(currentRoom);
  } else if (!strcmp(word1,"get")) {
    getItem(word2,currentRoom,inventory);
  } else if (!strcmp(word1,"inventory")) {
    listInventory(inventory);
  } else if (!strcmp(word1,"drop")) {
    dropItem(word2,currentRoom,inventory);
  } else if (!strcmp(word1,"list")) {
    cout << "You need: onion, mayo, relish, and tuna" << endl;
  }
  return wantToQuit;
}

// returns true if the input matches any of the first word commands
// in the validCommands array
bool isCommand(char command[10], char validCommands[][10]) {
  for (int i = 0; i < 8; i++) {// go through array
    if (!strcmp(command,validCommands[i])) {// compare input to each element in the array
      return true;
    }
  }
  return false;
}

// first checks if user has another word after 'go',
// then it changes current room depending on the direction (second word)
void goRoom(char direction[20], Room* &currentRoom) {
  
  if (!hasSecondWord(direction)) {// if there is no second word, ask again
    cout << "Go where?" << endl;
  } else if (currentRoom->checkExit(direction)) {// checks if the exit you asked for exists
    currentRoom->goExit(direction,currentRoom);// change current room
    describeRoom(currentRoom);
  } 
}

// returns true if the second input isn't ' ' (initialized value)
bool hasSecondWord(char word2[20]) {
  return (strcmp(word2," "));
}

// lists what you have in your inventory
void listInventory(vector<Item*> inventory) {
  int length = inventory.size();
  if (length < 1) {
    cout << "Your inventory is empty." << endl;
  } else {
    cout << "You have:" << endl;
    for (int i = 0; i < length; i++) {
      cout << inventory[i]->name << endl;
    }
  }
}

// puts the item in your inventory and removes it from the room
// checks if item exists
void getItem(char itemname[20], Room* &currentRoom, vector<Item*> &inventory) {
  int length = currentRoom->items.size();
  bool itemFound = false;
  // goes through inventory and 'gets' the item if input matches a name
  for (int i = 0; i < length; i++) {
    if (!strcmp(itemname,(currentRoom->items[i]->name))) {// if input = item name
      inventory.push_back(currentRoom->items[i]);// add item to inventory
      currentRoom->items.erase(currentRoom->items.begin()+i);// remove from room
      cout << "Item picked up." << endl << endl;
      itemFound = true;
    }
  }
  if (!itemFound) {
    cout << "That item doesn't exist!" << endl;
  }
}

// removes item from inventory and adds it to the room
// also check if the item exists
void dropItem(char itemname[20], Room* &currentRoom, vector<Item*> &inventory) {
  int length = inventory.size();
  bool itemFound = false;
  // goes through inventory and 'drops' the item if input matches a name
  for (int i = 0; i < length; i++) {
    if (!strcmp(itemname,(inventory[i]->name))) {// if input = item name
      currentRoom->items.push_back(inventory[i]);// adds item to room
      inventory.erase(inventory.begin()+i);// removes item from inventory
      cout << "Item dropped." << endl << endl;
      itemFound = true;
    }
  }
  if (!itemFound) {
    cout << "That item doesn't exist!" << endl;
  }
}

//output the room's description, exits, and items
void describeRoom(Room* currentRoom) {
  
  cout << currentRoom->description << endl;// output room-specific description
  currentRoom->listExits();// list it's exits
  int length = currentRoom->items.size();
  if (length > 0) {// output all items
    cout << "Items in this room: " << endl;
    for (int i = 0; i < length; i++) {
      cout << currentRoom->items[i]->name << endl;
    }
  } else {
    cout << "There are no items in this room." << endl;
  }
  cout << endl;
}

