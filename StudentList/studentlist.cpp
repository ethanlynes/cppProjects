#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

/*
Ethan Lynes
Date
yeet
*/

struct Student {
  char first_name[10];
  char last_name[10];
  int id;
  float gpa;
};

void addStudent(vector<Student> students);

int main() {
  bool running = true;

  vector<Student> students;

  char input[5];
  while (running == true) {

    cout << "actions: ADD, DEL, LIST, QUIT" << endl;
    cout << input << endl;
    cin.get(input,5);
    cin.get();

    if (input[0] == 'A' &&
	input[1] == 'D' &&
	input[2] == 'D') {
      
      addStudent(students);
    } else if (input[0] == 'D' &&
	       input[1] == 'E' &&
	       input[2] == 'L') {


      cout << endl;
    } else if (input[0] == 'L' &&
	       input[1] == 'I' &&
	       input[2] == 'S' &&
	       input[3] == 'T') {

      cout << "Size: " << students.size() << endl;
      cout << endl;
    } else if (input[0] == 'Q' &&
	       input[1] == 'U' &&
	       input[2] == 'I' &&
	       input[3] == 'T') {

      cout << "Terminating..." << endl;
      running = false;
    } else {
      cout << "Invalid command" << endl;
      running = false;
    }
  }
}

void addStudent(vector<Student> students) {
  Student temp;
  cout << "First name: ";
  cin.get(temp.first_name,10);
  cin.get();
  
  cout << "Last name: ";
  cin.get(temp.last_name,10);
  cin.get();
  /*
  cout << "ID: ";
  cin >> temp.id;
  
  cout << "GPA: ";
  cin >> temp.gpa;
  */
  
  students.push_back(temp);
  cout << endl;
}
