#include <iostream>
#include <iomanip>
#include <cstring>
#include "node.h"
#include "student.h"

using namespace std;

/*
Name: Ethan Lynes
Date: 1/10/20
Purpose: A student list using linked lists instead of vectors. Main idea was to learn how to work with nodes and pointers instead of having the vector do it for me
File: main file
*/

//construct
void add(Node* &head, Student* newstudent, Node* current, int &studentcount);
void print(Node* &head, Node* next);
void del(int id, Node* current, Node* prev, Node* &head, int &studentcount, float &gpacount);

//main function
int main() {
  Node* head = NULL;
  // base vars
  cout << "Commands: ADD, PRINT, DELETE, AVERAGE, QUIT" << endl;
  bool running = true;
  float gpacount = 0;
  int studentcount = 0;

  // running loop (ends when you type quit)
  while (running) {

    // takes input and converts characters to lowercase
    char input[10];
    cin.get(input,10);
    cin.get();
    int len = strlen(input);
    for (int i = 0; i < len; i++) {
      input[i] = tolower(input[i]);
    }

    // checks input for all commands
    if (strcmp(input,"add") == 0) {// if input = 'add'

      // takes input for student parameters
      cout << "name: ";
      char name[100];
      cin.get(name,100);
      cin.get();

      cout << "id: ";
      int id;
      cin >> id;
      cin.get();

      cout << "gpa: ";
      float gpa;
      cin >> gpa;
      cin.get();
      // creates a temporary student
      Student* temp = new Student(id,name,gpa);

      gpacount += gpa;
      // runs add method
      add(head,temp,head,studentcount);
      cout << endl;

    } else if (strcmp(input,"print") == 0) {// if input =
        
      print(head,head);
      
    } else if (strcmp(input,"delete") == 0) {

      int id;
      cout << "Enter the id of the student you want to delete: " << endl;
      cin >> id;
      cin.get();

      del(id,head,NULL,head,studentcount,gpacount);

    } else if (strcmp(input,"average") == 0) {
      cout << "Average GPA: " << (gpacount/studentcount) << endl;
    } else if (strcmp(input,"quit") == 0) {
      running = false;
    }
    
  }
  return 0;
}

void add(Node* &head, Student* newstudent, Node* current, int &studentcount) {
  int id = newstudent->id;
  if (current == NULL) {// empty list
    head = new Node(newstudent);
    cout << "student added" << endl;
    studentcount++;
  } else {// something in list
    if (head->getNext() == NULL) {// only node in the list
      
      if (current->getStudent()->id < id) {
	// if node has a lower id, add student to end
	current->setNext(new Node(newstudent));
	
      } else if (current->getStudent()->id > id) {
	// if node has greater id, add student to beginning
	head = new Node(newstudent);
	head->setNext(current);
	
      }
      cout << "student added" << endl;
      studentcount++;
      
    } else {// more than 1
      if (current->getStudent()->id > id) {
	// if node has greater id, add student in front of it
	head = new Node(newstudent);
	head->setNext(current);
	cout << "student added" << endl;
	studentcount++;
	
      } else if (current->getNext() == NULL) {
	// checks if its the last node
	current->setNext(new Node(newstudent));
	cout << "student added" << endl;
	studentcount++;

      } else if (current->getStudent()->id < id &&
      current->getNext()->getStudent()->id > id) {

	//checks if it can fit student between current and next node
	Node* temp = new Node(newstudent);
	temp->setNext(current->getNext());
	current->setNext(temp);
	
	cout << "student added" << endl;
	studentcount++;
	
      } else {// current's id is less and next is also less

	add(head,newstudent,current->getNext(),studentcount);

      }
    }
  }
}

// func for printing out all students
void print(Node* &head, Node* next) {
  // (gpa decimal thingy)
  cout << fixed;
  cout << setprecision(2);
  // 
  if (head == NULL) {
    cout << "This list is empty" << endl;
    return;
  }
  if (next == head) {
    cout <<  "list: " << endl;
  }
  if (next != NULL) {
    cout << next->getStudent()->name << ", " << next->getStudent()->id
	 << ", " << next->getStudent()->gpa << endl;
    if (next->getNext() == NULL) {
      cout << endl;
    }
    print(head,next->getNext());
  }
}

void del(int id, Node* current, Node* prev, Node* &head, int &studentcount, float &gpacount) {

  if (current == NULL) {
    cout << "That student doesn't exist!" << endl;
    return;
  }

  if (current->getStudent()->id == id) {// current matches the id

    if (prev == NULL) {// first node

      if (current->getNext() != NULL) {// first of many

	head = current->getNext();
	
      } else {// first and last (only node)

	head = NULL;
	
      }
      gpacount -= current->getStudent()->gpa;
      delete current;
      studentcount--;
      
    } else if (current->getNext() == NULL) {// last node

      prev->setNext(NULL);// remove prev next link
      
      gpacount -= current->getStudent()->gpa;
      delete current;
      studentcount--;

    } else {// nodes surrounding

      prev->setNext(current->getNext());

      gpacount -= current->getStudent()->gpa;
      delete current;
      studentcount--;

    }
    cout << id << " was deleted." << endl << endl;
    
  } else {// check next node

    del(id,current->getNext(),current,head,studentcount,gpacount);
  }
}
