#include <iostream>
#include "student.h"

using namespace std;

Student::Student(int newid) {
  id = newid;
}

Student::~Student() {
  cout << "point 1.1" << endl;
  cout << "point 1.2" << endl;
}
