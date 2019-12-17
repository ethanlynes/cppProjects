#include <iostream>
#include "node.h"
#include "student.h"

using namespace std;

/*
File: node class
*/

Node::Node(Student* newstudent) {
  student = newstudent;
  next = NULL;
}

Node::~Node() {
  cout << "point 1" << endl;
  delete student;
  cout << "point 2" << endl;
  next = NULL;
  cout << "point 3" << endl;
}

Student* Node::getStudent() {
  return student;
}

void Node::setNext(Node* newnext) {
  next = newnext;
}

Node* Node::getNext() {
  return next;
}
