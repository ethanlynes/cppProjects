#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

/*
This is Palindrome
Name: Ethan Lynes
Class: CPP & Data Structures
Date:10/1
Description:
takes in a string, removes all characters that aren't letters, then checks if it's a palindrome. Report if it is or not.

*/


int main() {

  char firstString[80];
  
  cin.get(firstString, 80);
  cin.get();
  //user input
  int length = strlen(firstString);
  
  for (int i = 0; i < length; i++) {//goes through the input, if it's a letter, make it lowercase

     firstString[i] = tolower(firstString[i]);
  }

  cout << "making lowercase: " << firstString << endl;

  int count = 0;
  for (int i = 0; i < length; i++) {//if an index isn't a lowercase letter, push it to the end of the string, then remove
    if (int(firstString[i]) > 96 && int(firstString[i]) < 123) {
      firstString[count++] = firstString[i];
    }  
  }
  firstString[count] = '\0';
  
  cout << "removing non-letters: " << firstString << endl;
  
  
  length = strlen(firstString) - 1;
  char secondString[length];
  int count2 = length;
  
  for (int i = 0; i <= length; i++) {//makes a backwards string into a second character array
    secondString[count2--] = firstString[i];
    //basically, it takes the length of the first string, uses that to edit the index of the second string, then works backwards until it's iterated through the entire string
  }
  secondString[length+1] = '\0';

  cout << "backwards string: " << secondString << endl;

  if (strcmp(firstString, secondString) == 0) {//checks if the backwards string is equal to the first string
    cout << "your string IS a palindrome" << endl;
  } else {
    cout << "your string is NOT a palindrome" << endl;
  }

  
  return 0;
}
