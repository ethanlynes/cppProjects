#include <iostream>
#include <cstring>
#include "student.h"

/*
Ethan Lynes
student class file
1/23/20
*/

using namespace std;
//constructor
Student::Student(int newid, char* newname, float newgpa) {
  id = newid;
  strcpy(name,newname);
  gpa = newgpa;
}
//destructor
Student::~Student() {
  
}
