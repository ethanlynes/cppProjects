#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int main() {

  char yeet[80];

  cin.get(yeet, 80);
  cin.get();
  
  for (int i = 0; i < strlen(yeet); i++) {

     yeet[i] = tolower(yeet[i]);
  }

  cout << yeet << endl;

  int count = 0;
  for (int i = 0; i < strlen(yeet); i++) {
    if (int(yeet[i]) > 96 && int(yeet[i]) < 123) {
      yeet[count++] = yeet[i];
    }  
  }
  
  yeet[count] = '\0';

  char teey[strlen(yeet)-1];
  count = strlen(teey);
  for (int i = 0; i <= strlen(yeet); i++) {
    teey[count--] = yeet[i];
    cout << teey << endl;
   
  }

  //teey[strlen(teey)] = '\0';

  cout << "default string: " << yeet << endl;
  
  cout << "backwards string: " << teey << endl;
  

  
  return 0;
}
