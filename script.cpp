#include <iostream>

using namespace std;

void printBoard(char board[3][3]);
int convertRow(char in[2]);
int convertClm(char in[2]);
char checkWin(char board[3][3]);
char checkTie(char board[3][3]);

int main() {
  char board[3][3];
  char input[2];
  bool xTurn = true;
  bool end = false;
  char winner;
  char playing = 'Y';
  int xWins = 0;
  int oWins = 0;
  int ties = 0;
  char oMove = 'O';
  char xMove = 'X';

  while(playing == 'Y'){//clears board
    for(int clm = 0; clm < 3 ; clm++){
      for(int row = 0; row < 3; row++){
        board[row][clm] = ' ';
      }
    }
    cout << board[0][0] << endl;
    winner = ' ';
    printBoard(board);
    while(end == false){
      if(xTurn == true){//X turn
        cout << "X turn: " << endl;
        cin >> input;
        bool move = true;
        while(move == true){//input
          if(board[convertRow(input)][convertClm(input)] == ' '){
            board[convertRow(input)][convertClm(input)] = xMove;
            printBoard(board);
            move = false;
          }else{//illegal move
            cout << "Illegal move: you may only play in empty, available spaces " << endl;
            cin >> input;
            move = true;
          }
        }
        xTurn = false;
	if(checkWin(board) == xMove || checkWin(board) == oMove || checkTie(board) == 'y'){
	  end = true;
	}
      }else{//O turn
        cout << "O turn: " << endl;
        cin >> input;
        bool move = true;
        while(move == true){
          if(board[convertRow(input)][convertClm(input)] == ' '){
            board[convertRow(input)][convertClm(input)] = oMove;
            printBoard(board);
            move = false;
          }else{
            cout << "Illegal move: you may only play in empty, available spaces " << endl;
            cin >> input;
            move = true;
          }
        }
        xTurn = true;
	if(checkWin(board) == xMove || checkWin(board) == oMove || checkTie(board) == 'y'){
	  end = true;
        }
      }
    }
    if(end == true){
      if(checkWin(board) == xMove){
	xWins++;
        cout << "Congratulations X on your " << xWins << " win!" << endl;
      }else if (checkWin(board) == oMove){
	oMove++;
	cout << "Congratulations O on your " << oWins << " win!" << endl;
      }else{
	ties++;
	cout << "This has been your " << ties << " tie" << endl;
      }
    }
    //checks if player plays again
    bool playAgain = true;
    cout << "Continue playing (Y/N)?" << endl;
    while(playAgain == true){
      char response;
      cin >> response;
      if(response == 'Y'){//reset game
        playing = 'Y';
        playAgain = false;
        end = false;
        xTurn = true;
      }else if(response == 'N'){//end game
        playing = 'N';
        playAgain = false;
      }else{
        cout << "Invalid response: input Y for yes and N for no" << endl;
        playAgain = true;
      }
    }
  }
}

void printBoard(char board[3][3]){
    cout << "  a b c" << endl;
    cout << "1 " << board[0][0] << " " << board[1][0] << " " << board[2][0] << endl;
    cout << "2 " << board[0][1] << " " << board[1][1] << " " << board[2][1] << endl;
    cout << "3 " << board[0][2] << " " << board[1][2] << " " << board[2][2] << endl;
}

int convertRow(char in[2]) {//gets row
  if(in[0] == 'a'){
    return 0;
  }else if(in[0] == 'b'){
    return 1;
  }else if(in[0] == 'c'){
    return 2;
  }else{
    return ' ';
  }
}

int convertClm(char in[2]) {//gets column
  if(in[1] == '1'){
    return 0;
  }
  if(in[1] == '2'){
    return 1;
  }
  if(in[1] == '3'){
    return 2;
  }else{
    return ' ';
  }
}

char checkWin(char board[3][3]) {
    char xMove = 'X';
    char oMove = 'O';
    //x
    if(board[0][0] == xMove && board[0][1] == xMove && board[0][2] == xMove){//top row 
      return xMove;
    }else if(board[1][0] == xMove && board[1][1] == xMove && board[1][2] == xMove){//mid row
      return xMove;
    }else if(board[2][0] == xMove && board[2][1] == xMove && board[2][2] == xMove){//low row
      return xMove;
    }else if(board[0][0] == xMove && board[1][0] == xMove && board[2][0] == xMove){//left clm
      return xMove;
    }else if(board[0][1] == xMove && board[1][1] == xMove && board[2][1] == xMove){//mid clm
      return xMove;
    }else if(board[0][2] == xMove && board[1][2] == xMove && board[2][2] == xMove){//right clm
      return xMove;
    }else if(board[0][0] == xMove && board[1][1] == xMove && board[2][2] == xMove){//diag from top left
      return xMove;
    }else if(board[0][2] == xMove && board[1][1] == xMove && board[2][0] == xMove){//diag form low left
      return xMove;
    }
    //o
    else if(board[0][0] == oMove && board[0][1] == oMove && board[0][2] == oMove){//top row
      return oMove;
    }else if(board[1][0] == oMove && board[1][1] == oMove && board[1][2] == oMove){//mid row
      return oMove;
    }else if(board[2][0] == oMove && board[2][1] == oMove && board[2][2] == oMove){//low row 
      return oMove;
    }else if(board[0][0] == oMove && board[1][0] == oMove && board[2][0] == oMove){//left clm
      return oMove;
    }else if(board[0][1] == oMove && board[1][1] == oMove && board[2][1] == oMove){//mid clm
      return oMove;
    }else if(board[0][2] == oMove && board[1][2] == oMove && board[2][2] == oMove){//right clm
      return oMove;
    }else if(board[0][0] == oMove && board[1][1] == oMove && board[2][2] == oMove){//diag from top left
      return oMove;
    }else if(board[0][2] == oMove && board[1][1] == oMove && board[2][0] == oMove){//diag from low left
      return oMove;
    }else{
      return ' ';
    }
  }
  
  char checkTie(char board[3][3]) {
    //sees if board is full
    if(board[0][0] != ' ' && board[0][1] != ' ' && board[0][2] != ' '
     && board[1][0] != ' ' && board[1][1] != ' ' && board[1][2] != ' '
     && board[2][0] != ' ' && board[2][1] != ' ' && board[2][2] != ' '){
      return 'y';
    }else{
      return ' ';
    }
  }

