#include <iostream>
#include "node.h"
#include "student.h"

using namespace std;

/*
File: main file
*/

int main() {
  //students
  Student* jeff = new Student(1);
  Student* john = new Student(2);
  Student* jim = new Student(3);
  
  //nodes
  Node* node1 = new Node(jeff);
  Node* node2 = new Node(john);
  Node* node3 = new Node(jim);
  node1->setNext(node2);
  node2->setNext(node3);

  cout << "jeff's id: " << node1->getStudent()->id << endl;
  cout << "jeff's next node's id: " << node1->getNext()->getStudent()->id << endl;
  cout << "john's id: " << node2->getStudent()->id << endl;
  cout << "john's next node's id: " << node2->getNext()->getStudent()->id << endl;
  

  delete node2;
  node1->setNext(node3);
  cout << "deleted student john" << endl;
  cout << node1->getNext() << endl;
  cout <<
  
  return 0;
}
