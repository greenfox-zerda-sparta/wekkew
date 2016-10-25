#include <iostream>
using namespace std;

//Create an array which is an 8x8 matrix. This is a checkers board.
//White squares are represented by '_', black squares are represented by '#'

void fillBoard(string board[8][8]) {
		for (int row = 0; row < 8; row++) {
			for (int column = 0; column < 8; column++) {
				if ((row+column)%2 == 0) {
					board[row][column] = "_";
				}
				else {
					board[row][column] = "#";
				}
			}
		}
	}
//'W' represents white checkers, 'B' represents black checkers.

//Create a function that moves a certain checker from a position to an other. Should be called: "move"
//Create a function that gives You back the possible positions the checker can go to. Should be called: "possibleSteps"
//Create a function that takes down an other checker by letting the one jumping over the other. Should be called: "take"
//All checkers are represented by their indices.

//Print out the whole board. Make some moves and illustrate them by printing out the whole board again.
//Create a function to do so. it should be called "printBoard"
void printBoard(string board[8][8]) {
	for (int row = 0; row < 8; row++) {
		for (int column = 0; column < 8; column++) {
			cout << board[row][column];
		}
	cout << endl;
	}
}

int main(int argv, char** argc){
	string board[8][8];

	fillBoard(board);
	printBoard(board);
	return 0;
}
