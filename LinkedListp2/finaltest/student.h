#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>

using namespace std;

class Student {
 public:
  int id;
  char name[100];
  float gpa;
  Student(int newid, char* newname, float newgpa);
  ~Student();
};
#endif
