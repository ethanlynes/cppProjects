#include <iostream>
#include "node.h"

using namespace std;

/*
File: node class
*/

Node::Node(Student* newstudent) {
  student = newstudent;
}

Node::~Node() {

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
