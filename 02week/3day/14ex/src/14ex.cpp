#include <iostream>
using namespace std;

// This exercise is about implementing a game of Tic Tac Toe. You'll have to create a few functions operating on a matrix.
// (Array of arrays). The array will contain 0s where the playfield is empty. 1s where player 1 has placed an X, -1s where
// player 2 has placed an O. An example would look like this:
// {{1,0,0}, {0,0,0}, {0,0,-1}} After the first two steps.
// The program should be able to print out the playfield. A function doing this would get a pointer to the array representing
// the playfield. The result should look like this for the above example:
//
// X |  |
// --------
//   |  |
// --------
//   |  | O
//
// There should be a function that checks whether a field is empty.
// There should be a function that places a step for a player. This should employ the previous function to check whether this step is available.
// Please find a way to maintain the history for each game. The history needs to contain the coordinates where the player put their mark and the
// players ID (whether it's player one or two.)
// The functions placing the steps should add the step to the history when they have made it.
//
int board[3][3];
int stepCounter = 0;
void nextMove();
void printBoard() {
	for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				switch (board[i][j]) {
					case (0) :
						cout << "  |";
						break;
					case (1) :
						cout << " X|";
						break;
					case (-1) :
						cout << " O|";
						break;
				}
			}
			cout<< endl;
		}
}
void step(int x, int y) {
	if (x > 3 || y > 3) {
		cout << "Wrong place try again!" << endl;
		nextMove();
	}
	else {
		if (board[x][y] != 0) {
			cout << "This place has already taken, please choose another one!" << endl;
			nextMove();
		} else {
			if (stepCounter%2 == 0) {
				stepCounter++;
				board[x][y] = 1;
				nextMove();
			}
			if (stepCounter%2 == 1) {
				stepCounter++;
				board[x][y] = -1;
				nextMove();
			}
		}
	}
}
void nextMove() {
	printBoard();
	if (stepCounter >= 9) {
		cout << "VEEEEEGE" << endl;
		return;
	}
	cout << "Next step, please enter the X and then the Y coordinates of your move :" << endl;
	int x;
	cin >> x;
	int y;
	cin >> y;
	step(x, y);
}

void newGame() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			board[i][j] = 0;
		}
	}
	nextMove();
}

int main(int argc, char** argv) {
	newGame();

	return 0;
}
