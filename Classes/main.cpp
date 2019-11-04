#include <iostream>
#include <string.h>
#include "parent.h"

using namespace std;


int main() {
  Parent obj;
  obj.mynum = 3;
  cout << obj.returnNum() << endl;
}
