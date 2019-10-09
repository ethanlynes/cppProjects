#include <iostream>
using namespace std;

/*
Ethan Lynes
10/9/19
This program resembles the 2 player game "Tic Tac Toe", where you are given a 3x3 board to play on
each player takes turns marking 'x' or 'o' in an open spot until someone has 3 in a row,
or it results in a tie
*/

//functions
void printBoard(int board[][3], int BLANK, int X_MOVE, int O_MOVE);
void resetBoard(int board[][3], int BLANK);
bool checkWin(int board[][3], int player);
bool checkTie(int board[][3], int BLANK);

int main() {
  //constants
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
  
  //while you still want to play
  while (stillPlaying == true) {

    //init input, reset board layout
    char input[2];
    input[2] = '\0';
    resetBoard(board, BLANK);
    printBoard(board, BLANK, X_MOVE, O_MOVE);

    //ask for move
    cout << "input a letter and a number that corresponds " << endl << "with the row and column you want to play" << endl;

    //while no one has won or tied
    while (checkWin(board, X_MOVE) == false && checkWin(board, O_MOVE) == false && checkTie(board, BLANK) == false) {
      //input move
	cin.get(input, 3);
	cin.get();

	//filters input
	if (input[0] != 'a' && input[0] != 'b' && input[0] != 'c') {
	  cout << "row must be 'a', 'b', or 'c'" << endl;
	} else if (input[1] != '1' && input[1] != '2' && input[1] != '3') {
	  cout << "column must be '1', '2', or '3'" << endl;
	} else {

	  //changes your input into an index for the board
	  int row = input[0] - 'a';
	  int column = input[1] - '1';
	  //if the index you chose is blank, execute move
	  if (board[row][column] == BLANK) {
	    if (turn == X_TURN) {
	      board[row][column] = X_MOVE;
	      turn = O_TURN;
	    } else {
	      board[row][column] = O_MOVE;
	      turn = X_TURN;
	    }
	    //otherwise, say the spot is taken
	  } else {
	    cout << "that spot is taken" << endl;
	  }
	  //print board after move
	  cout << endl;
	  printBoard(board, BLANK, X_MOVE, O_MOVE);
   	}
	
      }
    //checks if x has 3 in a row
      if (checkWin(board, X_MOVE)) {

	cout << "x wins" << endl;
	xwins++;
	//checks if o has 3 in a row
      } else if (checkWin(board, O_MOVE)) {
	
	cout << "o wins" << endl;
	owins++;
	//otherwise result is a tie
      } else {
	
	cout << "result is a tie" << endl;
	numties++;
      }

      //outputs number of wins/ties
      cout << "X won " << xwins << " times" << endl;
      cout << "O won " << owins << " times" << endl;
      cout << "Total ties: " << numties << endl;

      //asks if you want to continue
      cout << "do you still want to play? type y to keep playing" << endl;
      char inp[10];
      cin.get(inp, 10);
      cin.get();
      if (inp[0] == 'y') {
	stillPlaying = true;
      } else {//if you input anything that isn't 'y', quit
	stillPlaying = false;
      }
   }
  
  return 0;
}
//function to reset the board to all blanks
//iterates through the board array and changes each index to 0, or BLANK
void resetBoard(int board[][3], int BLANK) {
  for (int row = 0; row < 3; row++) {
    for (int column = 0; column < 3; column++) {
      board[row][column] = BLANK;
    }
  }
}

//function for printing the board to the console
//iterates through the board and checks if the index is 0, 1, or 2
//if it's 0, print blank
//if it's 1, print X
//if it's 2, print O
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

//function for checking if a player has won
//given a player (xmove or omove), it checks each possible 3 in a row combination for that player
//if it finds a 3 in a row, return true. If it goes through all and no one has won, return false
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

//function for checking ties
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
