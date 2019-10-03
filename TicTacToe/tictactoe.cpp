#include <iostream>
using namespace std;

void printBoard(int board[][3], int BLANK, int X_MOVE, int O_MOVE);
void resetBoard(int board[][3], int BLANK);

int main() {

  int board[3][3];
  int BLANK = 0;
  int X_MOVE = 1;
  int O_MOVE = 2;
  int X_TURN = 0;
  int O_TURN = 1;
  int turn = X_TURN;

  int xwins = 0;
  int owins = 0;
  int numties = 0;
  bool stillPlaying = true;
  char input[2];
  input[2] = '\0';
  
  while (stillPlaying == true) {

    resetBoard(board, BLANK);
    printBoard(board, BLANK, X_MOVE, O_MOVE);

    cout << "input a letter and a number that corresponds " << endl << "with the row and column you want to play" << endl;
    cin.get(input, 3);
    cin.get();

    cout << "you entered: " << input << endl;
    if (input[0] != 'a' && input[0] != 'b' && input[0] != 'c') {
      cout << "row must be 'a', 'b', or 'c'" << endl;
    } else if (input[1] != '1' && input[1] != '2' && input[1] != '3') {
      cout << "column must be '1', '2', or '3'" << endl;
    } else {

      int row = input[0] - 'a';
      int column = input[1] - '1';
      if (board[row][column] == BLANK) {
	if (turn == X_TURN) {
	  board[row][column] = X_MOVE;
	  turn = O_MOVE;
	} else {
	  board[row][column] = O_MOVE;
	  turn = X_MOVE;
	}
      } else {
	cout << "that spot is taken" << endl;
      }
      printBoard(board, BLANK, X_MOVE, O_MOVE);
      
    }
    
    cout << "do you still want to play? type y to keep playing" << endl;
    char inp;
    cin >> inp;
    if (inp == 'y') {
      stillPlaying = true;
    } else {
      stillPlaying = false;
    }
    
    //stillPlaying = false;
  }
  
  return 0;
}

void resetBoard(int board[][3], int BLANK) {
  for (int row = 0; row < 3; row++) {
    for (int column = 0; column < 3; column++) {
      board[row][column] = BLANK;
    }
  }
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

bool checkWin(int player) {

  return false;
}
