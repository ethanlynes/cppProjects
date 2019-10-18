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
  char first_name[20];
  char last_name[20];
  int id;
  float gpa;
};

void addStudent(vector<Student> &students);
void listStudents(vector<Student> students);
void delStudent(vector<Student> &students, int id);

int main() {
  bool running = true;

  vector<Student> students;

  char input[5];
  while (running == true) {

    cout << "actions: ADD, DEL, LIST, QUIT" << endl;
    cin.get(input,5);
    cin.get();

    if (input[0] == 'A' &&
	input[1] == 'D' &&
	input[2] == 'D') {
      
      addStudent(students);
    } else if (input[0] == 'D' &&
	       input[1] == 'E' &&
	       input[2] == 'L') {

      int id;
      cout << "Enter the id of the student you want to remove" << endl;
      cin >> id;
      cin.get();
      delStudent(students, id);
    } else if (input[0] == 'L' &&
	       input[1] == 'I' &&
	       input[2] == 'S' &&
	       input[3] == 'T') {

      listStudents(students);
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

void addStudent(vector<Student> &students) {
  Student temp;
  cout << "First name: ";
  cin.get(temp.first_name,20);
  cin.get();
  
  cout << "Last name: ";
  cin.get(temp.last_name,20);
  cin.get();
  
  cout << "ID: ";
  cin >> temp.id;
  cin.get();
  
  cout << "GPA: ";
  cin >> temp.gpa;
  cin.get();
  
  students.push_back(temp);
  cout << endl;
}

void listStudents(vector<Student> students) {
  cout << "Size: " << students.size() << endl;
  for (int i = 0; i < students.size(); i++) {
    cout << students[i].first_name << " " << students[i].last_name << ", ";
    cout << "ID: " << students[i].id << ", ";
    cout.precision(3);
    cout.setf(ios::showpoint);
    cout << "GPA: " << students[i].gpa << endl;
  }
  cout << endl;
}

void delStudent(vector<Student> &students, int id) {
  for (int i = 0; i < students.size(); i++) {
    if (students[i].id == id) {
      students.erase(students.begin()+i);
    }
  }
  cout << endl;
}
