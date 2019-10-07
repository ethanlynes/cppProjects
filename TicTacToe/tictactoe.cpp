#include <iostream>
using namespace std;

void printBoard(int board[][3], int BLANK, int X_MOVE, int O_MOVE);
void resetBoard(int board[][3], int BLANK);
bool checkWin(int board[][3], int player);
bool checkTie(int board[][3], int BLANK);

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
  
    
  while (stillPlaying == true) {
    
    char input[2];
    input[2] = '\0';
    resetBoard(board, BLANK);
    printBoard(board, BLANK, X_MOVE, O_MOVE);

    cout << "input a letter and a number that corresponds " << endl << "with the row and column you want to play" << endl;

    while (checkWin(board, X_MOVE) == false && checkWin(board, O_MOVE) == false && checkTie(board, BLANK) == false) {
	cin.get(input, 3);
	cin.get();

	//cout << "you entered: " << input << endl;
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
	      turn = O_TURN;
	    } else {
	      board[row][column] = O_MOVE;
	      turn = X_TURN;
	    }
	  } else {
	    cout << "that spot is taken" << endl;
	  }
	  cout << endl;
	  printBoard(board, BLANK, X_MOVE, O_MOVE);
   	}
	
      }
      
      if (checkWin(board, X_MOVE)) {

	cout << "x wins" << endl;
	xwins++;
      } else if (checkWin(board, O_MOVE)) {
	
	cout << "o wins" << endl;
	owins++;
      } else {
	
	cout << "result is a tie" << endl;
	numties++;
      }

      cout << "X won " << xwins << " times" << endl;
      cout << "O won " << owins << " times" << endl;
      cout << "Total ties: " << numties << endl;
      
      cout << "do you still want to play? type y to keep playing" << endl;
      char inp[10];
      cin.get(inp, 10);
      cin.get();
      if (inp[0] == 'y') {
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

 bool checkWin(int board[][3], int player) {//checks if a player has 3 in a row after a move
  if (board[0][0] == player && board[0][1] == player && board[0][2] == player) {
    return true;
  } else if (board[1][0] == player && board[1][1] == player && board[1][2] == player) {
    return true;
  } else if (board[2][0] == player && board[2][1] == player && board[2][2] == player) {
    return true;
  } else if (board[0][0] == player && board[1][0] == player && board[2][0] == player) {
    return true;
  } else if (board[0][1] == player && board[1][1] == player && board[2][1] == player) {
    return true;
  } else if (board[0][2] == player && board[1][2] == player && board[2][2] == player) {
    return true;
  } else if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
    return true;
  } else if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
    return true;
  }//if anyone has won, checkWin returns true, ending the while loop
  
  return false;
}

 
 bool checkTie(int board[][3], int BLANK) {
   for (int row = 0; row < 3; row++) {//checks through the board for open spots
    for (int column = 0; column < 3; column++) {
      if (board[row][column] == BLANK) {
	return false;//if it finds an open spot, no tie
      }
    }
  }
   return true;//if there isn't any open spots, results in a tie
}
