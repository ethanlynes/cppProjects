#ifndef NODE_H
#define NODE_H
#include <iostream>
#include "student.h"

using namespace std;

/*
File: node header
*/

class Node {
 public:
  Node(Student* newstudent);
  ~Node();
  Student* getStudent();
  void setNext(Node* newnext);
  Node* getNext();
  Student* student;
  Node* next;
};
#endif
