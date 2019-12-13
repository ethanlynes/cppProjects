#include <iostream>
#include "student.h"

using namespace std;

Student::Student(int newid) {
  id = newid;
}

Student::~Student() {
  delete &id;
}
