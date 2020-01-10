#include <iostream>
#include <cstring>
#include "student.h"

using namespace std;

Student::Student(int newid, char* newname, float newgpa) {
  id = newid;
  strcpy(name,newname);
  gpa = newgpa;
}

Student::~Student() {
  
}
