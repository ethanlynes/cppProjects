#include <iostream>
using namespace std;

int main() {
  int keepGoing = 1;
  char ask;
  
  while (keepGoing == 1) {
    keepGoing = 0;
    cout << "this program is running" << endl;

    cout << "Do you want to keep going? y or n" << endl;
    cin >> ask;
    if (ask == 'y') {
      keepGoing = 1;
    }
  }
  return 0;
}
