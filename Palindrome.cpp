#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int main() {

  char yeet[80];

  cin.get(yeet, 80);
  cin.get();
  int count = 0;

  for (int i = 0; i < strlen(yeet); i++) {

    putchar(tolower(yeet[i]));
  }
  
  /*for (int i = 0; i < strlen(yeet); i++) {
    if (yeet[i] != ' ') {
      yeet[count] = yeet[i];
      count++;
    }
    
  }
  yeet[count] = '\0';
  */
  cout << yeet << endl;
  
  return 0;
}
