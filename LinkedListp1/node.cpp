#include <iostream>
#include "node.h"
#include "student.h"

using namespace std;

/*
File: node class
*/

//constructor
Node::Node(Student* newstudent) {
  student = newstudent;
  next = NULL;
}

//destructor
Node::~Node() {
  delete student;
  next = NULL;
}

//get student, returns student in node
Student* Node::getStudent() {
  return student;
}

//sets next pointer
void Node::setNext(Node* newnext) {
  next = newnext;
}

//gets next pointer
Node* Node::getNext() {
  return next;
}
