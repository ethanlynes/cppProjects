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
  student->~Student();
  delete next;
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
