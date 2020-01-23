#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>

using namespace std;

/*
Ethan Lynes
student class header file
1/23/20
*/

class Student {
 public:
  //vars
  int id;
  char name[100];
  float gpa;
  //constructor + destructor
  Student(int newid, char* newname, float newgpa);
  ~Student();
};
#endif
