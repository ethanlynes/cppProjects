#include <iostream>
using namespace std;

void printBoard(int board[][3], int BLANK, int X_MOVE, int O_MOVE);

int main() {

  int board[3][3];
  int BLANK = 0;
  int X_MOVE = 1;
  int O_MOVE = 2;
  int X_TURN = 0;
  int O_TURN = 1;
  int turn = X_TURN;
  
  bool stillPlaying = true;

  while (stillPlaying == true) {

    printBoard(board, BLANK, X_MOVE, O_MOVE);
    
    stillPlaying = false;
  }
  
  return 0;
}

void printBoard(int board[][3], int BLANK, int X_MOVE, int O_MOVE) {
  cout << "  1 2 3" << endl;
    for (int row = 0; row < 3; row++) {
      cout << (char)('a'+row) << " ";
      for (int column = 0; column < 3; column++) {
	if (board[row][column] == BLANK) {
	  cout << "  ";
	} else if (board[row][column] == X_MOVE) {
	  cout << "X ";
	} else if (board[row][column] == O_MOVE) {
	  cout << "O ";
	}
      }
      cout << endl;
    }
}
