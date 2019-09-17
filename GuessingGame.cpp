#include <iostream>
using namespace std;
#include <cstdlib>

int main() {
  int keepGoing = 1;
  char askQuit;
  int askNum;
  int numGuess = 0;
  int hasGuessed = 0;
  
  
  while (keepGoing == 1) {

    srand(time(NULL));
    int random = (rand() % 100 + 1);
  
    keepGoing = 0;

    while (hasGuessed == 0) {
      cout << random << endl;
      cout << "guess a random number from 1 - 100" << endl;
      cin >> askNum;

      if (askNum < random) {
	cout << "your number is less than the number generated" << endl;
      } else if (askNum > random) {
	cout << "your number is greater than the number generated" << endl;
      } else if (askNum == random) {
	cout << "you guessed the number!" << endl;
	hasGuessed = 1;
      }

    }
    
    cout << "Do you want to play again? y or n" << endl;
    cin >> askQuit;
    
    if (askQuit == 'y') {
      keepGoing = 1;
      hasGuessed = 0;
    } else if (askQuit == 'n') {
      keepGoing = 0;
    } else {
      cout << "You entered neither y or n, terminating the program" << endl;
    }
  }
  return 0;
}
