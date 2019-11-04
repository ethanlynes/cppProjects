#include <iostream>
#include <cstring>
#include <vector>
#include <iomanip>
using namespace std;

/*
 Ethan Lynes

 Date: 10/22/19

 This program resembles a student data system. You are able to type a few commands
 that will allow you to manipulate the data. There are commands to add students and delete students.
 There are also commands for listing the students in the system and quitting the program entirely.
*/

// student struct
struct Student {
  char first_name[20];
  char last_name[20];
  int id;
  float gpa;
};

// init methods
void addStudent(vector<Student*> &students);
void listStudents(vector<Student*> students);
void delStudent(vector<Student*> &students, int id);

int main() {
  bool running = true;

  // vector of students
  vector<Student*> students;

  char input[5];
  //loops program until running = false
  while (running == true) {

    // asks user for a command
    cout << "actions: ADD, DEL, LIST, QUIT" << endl;
    cin.get(input,5);
    cin.get();

    // checks which command
    if (strcmp(input,"ADD") == 0) {

      // if ADD, call addstudent method
      addStudent(students);
    } else if (strcmp(input,"DEL") == 0) {

      // if DEL, ask for a student id and calls deletestudent method
      int id;
      cout << "Enter the id of the student you want to remove" << endl;
      cin >> id;
      cin.get();
      delStudent(students, id);
    } else if (strcmp(input,"LIST") == 0) {

      // if LIST, call liststudents method
      listStudents(students);
    } else if (strcmp(input,"QUIT") == 0) {

      // if QUIT, end while loop, ending the program
      cout << "Terminating..." << endl;
      running = false;
    } else {

      // if user input is invalid, throw error message and quit program
      cout << "Invalid command" << endl;
      running = false;
    }
  }
}


// method for adding students to the vector
void addStudent(vector<Student*> &students) {

  // creates a temporary student struct
  Student temp;

  // asks for user input for a name, id, and gpa
  // adds each to the student struct
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

  // adds the data from the temporary student to the vector
  (*students).push_back(temp);
  cout << endl;
}


// method for listing students to the console
void listStudents(vector<Student*> students) {

  // outputs the vector's size (number of students)
  cout << "Size: " << students.size() << endl;

  // iterates through the vector
  for (int i = 0; i < students.size(); i++) {

    // for each student, output their first name, last name, and id
    cout << students[i]->first_name << " " << students[i]->last_name << ", ";
    cout << "ID: " << students[i]->id << ", ";

    // set the gpa to show 2 decimal places
    cout << fixed;
    cout << setprecision(2);

    // output their gpa
    cout << "GPA: " << students[i]->gpa << endl;
  }
  cout << endl;
}


// method for deleting students from the vector
void delStudent(vector<Student*> &students, int id) {

  // iterates through the vector
  for (int i = 0; i < students.size(); i++) {
    
    // checks if a student's id is equal to the input given
    if (students[i]->id == id) {
      delete students[i];
      // if so, remove the student's data from the vector
      students.erase(students.begin()+i);
    }
  }
  cout << endl;
}
