#include <iostream>
using namespace std;
#include <cstdlib>

int main() {
  int keepGoing = 1;
  char askQuit;
  int askNum;
  int numGuess = 0;
  int hasGuessed = 0;
  //base vars
  
  while (keepGoing == 1) {//main loop

    srand(time(NULL));
    int random = (rand() % 100 + 1);
    //generates random number
    keepGoing = 0;
    //sets up a failsafe for the while loop
    
    while (hasGuessed == 0) {//while the user hasn't guessed the number
      
      cout << "guess a random number from 1 - 100" << endl;//ask user to guess
      cin >> askNum;
      numGuess++;//adds to guesses
      //tells the user if they guessed correctly, and if not says if it's greater or less than
      if (askNum < random) {
	cout << "your guess is less than the number generated" << endl;
      } else if (askNum > random) {
	cout << "your guess is greater than the number generated" << endl;
      } else if (askNum == random) {
	cout << "you guessed the correct number!" << endl;
	hasGuessed = 1;//ends asking loop
	cout << "you guessed " << numGuess << " times" << endl;//outputs number of guesses
      }

    }
    //asks if user wants to play again
    cout << "Do you want to play again? y or n" << endl;
    cin >> askQuit;
    //filters answers
    if (askQuit == 'y') {
      keepGoing = 1;
      hasGuessed = 0;
      numGuess = 0;//resets variables if user wants to restart
    } else if (askQuit == 'n') {
      keepGoing = 0;//quits program
    } else {
      cout << "You entered neither y or n, terminating the program" << endl;
    }
  }
  return 0;
}
