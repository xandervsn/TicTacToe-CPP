#include <iostream>

using namespace std;

void printBoard(char board[3][3]);
int getRow(char in[2]);
int getClm(char in[2]);

int main() {
  char board[3][3];
  char input[2];
  bool xTurn = true;
  bool end = false;
  char winner;
  char playing = 'y';
  int xWins = 0;
  int oWins = 0;
  int ties = 0;
  char oMove = 'O';
  char xMove = 'X';

  while (playing == 'y') {//clears board
    for (int clm = 0; clm < 3 ; clm++) {
      for (int row = 0; row < 3; row++) {
        board[row][clm] = ' ';
      }
    }
    winner = ' ';
    printBoard(board);
    while (end == false) {
      if (xTurn == true) {//X turn
        cout << "X turn: " << endl;
        cin >> input;
        bool move = true;
        while (move == true) {//input
          if (board[getRow(input)][getClm(input)] == ' ') {
            board[getRow(input)][getClm(input)] = xMove;
            printBoard(board);
            move = false;
          }
          else {//illegal move
            cout << "Illegal move, try again: " << endl;
            cin >> input;
            move = true;
          }
        }
        xTurn = false;
      }
      else {//O turn
        cout << "O turn: " << endl;
        cin >> input;
        bool move = true;
        while (move == true) {
          if (board[getRow(input)][getClm(input)] == ' ') {
            board[getRow(input)][getClm(input)] = oMove;
            printBoard(board);
            move = false;
          }
          else {
            cout << "Illegal move: you may only play in empty, available spaces " << endl;
            cin >> input;
            move = true;
          }
        }
        xTurn = true;
      }
    }
    //checks if player plays again
    bool playAgain = true;
    cout << "Continue playing (Y/N)?" << endl;
    while (playAgain == true) {
      char response;
      cin >> response;
      if (response == 'y') {//reset game
        playing = 'y';
        playAgain = false;
        end = false;
        xTurn = true;
      }
      else if (response == 'n') {//end game
        playing = 'n';
        playAgain = false;
      }
      else {
        cout << "Invalid response: input Y for yes and N for no" << endl;
        playAgain = true;
      }
    }
  }
}

void printBoard(char board[3][3]) {
  cout << "  a b c" << endl;
  cout << "1 ";
  for (int i = 0; i < 3; i++) {//row 1
    cout << board[i][0] << " ";
  }
  cout << endl;
  cout << "2 ";
  for (int i = 0; i < 3; i++) {//row 2
    cout << board[i][1] << " ";
  }
  cout << endl;
  cout << "3 ";
  for (int i = 0; i < 3; i++) {//row 3
    cout << board[i][2] << " ";
  }
  cout << endl;
}

int getRow(char in[2]) {//gets row
  if (in[0] == 'a') {
    return 0;
  }
  else if (in[0] == 'b') {
    return 1;
  }
  else if (in[0] == 'c') {
    return 2;
  }
  else {
    return ' ';
  }
}

int getClm(char in[2]) {//gets column
  if (in[1] == '1') {
    return 0;
  }
  if (in[1] == '2') {
    return 1;
  }
  if (in[1] == '3') {
    return 2;
  }
  else {
    return ' ';
  }
}
