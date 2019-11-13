#include <iostream>
#include "movie.h"

using namespace std;


int main() {
  Movie movie;
  movie.year = 2003;
  cout << movie.year << endl;
  movie.title[20] = "yeeties";
  cout << movie.title << endl;
}
