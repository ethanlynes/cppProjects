#include <iostream>
#include "node.h"
#include "student.h"

using namespace std;

/*
File: main file
*/

int main() {

  Student* jeff = new Student(0);
  Student* john = new Student(1);

  Node* node = new Node(jeff);
  cout << "jeff's id: " << node->getStudent()->id << endl;
  cout << "next node: " << node->getNext() << endl;
  cout << endl;
  
  Node* node2 = new Node(john);
  node->setNext(node2);
  cout << "added \"john\"" << endl;
  cout << endl;
  
  cout << "jeff's id: " << node->getStudent()->id << endl;
  cout << "jeff's next node (john): " << node->getNext() << endl;
  cout << "john's id: " << node2->getStudent()->id << endl;
  
  return 0;
}
/*
void add(Node* &head, Student* newstudent) {
  Node* current = head;
  if (current == NULL) {
    head = new Node(newstudent);
  } else {
    while (current->getNext() != NULL) {
      current = current->getNext();
    }
    current->setNext(new Node(newstudent));
  }
}


void print(Node* &head, Node* next) {
  if (next == head) {
    cout << "list: " << endl;
  }
  if (next != NULL) {
    cout << next->getStudent()->id << endl;
    print(head,next->getNext());
  }
}
*/
