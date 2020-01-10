/*
Jason Zhang
12/19/2019
Linked Lists
*/

#include <iostream>
#include <cstring>
#include "Student.h"

#ifndef NODE_H
#define NODE_H

using namespace std;

class Node{
 public:
  //constructor
  Node(Student*);
  //get the student
  Student* getStudent();
  //set the next node
  void setNext(Node*);
  //get the next node
  Node* getNext();
  //deconstructor
  ~Node();
 private:
  //student
  Student* student;
  //next node
  Node* next;
};
#endif
