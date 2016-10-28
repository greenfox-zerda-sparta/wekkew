#include <iostream>
#include <string>
#include <ctype.h>

using namespace std;

string word = "EVOSOFT";
int length = word.length();
int solution[7];
int guessCounter = 7;
void hangman();
void guess();
int main();

void print(int* array) {
  bool endgame = true;
  for (int i = 0; i < length; i++) {
    if (array[i] == 1) {
      cout << word[i];
    }
    else {
      cout << "_";
      endgame = false;
    }
  }
  cout << endl << endl;
  if (endgame) {
   cout << "You have won! :)" << endl;
   cout << "Play again? (y/n)" << endl;
    char exit;
    cin >> exit;
    if (exit == 'y' || exit == 'Y') {
      main();
    } else {
      return;
    }
  } else {
    hangman();
  }
}

void check(char a) {
  bool badTipp = true;
  for (int i = 0; i < length; i++) {
    if (a == word[i]) {
      solution[i] = 1;
      badTipp = false;
    }
  }
  if (badTipp) {
    guessCounter--;
    cout << "Wrong" << endl << endl;
  }
  print(solution);
}

void guess() {
  cout << "Enter your guess! : " << endl;
  char tipp;
  cin >> tipp;
  cout << endl;
  if (tipp < 'A' || tipp > 'Z') {
    cout << "Enter a capital letter A-Z, please!" << endl;
    guess();
  } else {
    check(tipp);
  }
}

void hangman() {
  string man[7] = {"   ______ ", "   |    | ", "   |    O ", "   |   /|\\ ", "   |   / \\ ", " __|______ ", "|         | "};
  for (int i = guessCounter; i < 7; i++) {
    cout << man[i] << endl;
  }
  if (guessCounter == 0) {
    cout << "Game over! :( " << endl;
    cout << "Play again? (y/n)" << endl;
    char exit;
    cin >> exit;
    if (exit == 'y' || exit == 'Y') {
      main();
    } else {
      return;
    }

    return;
  } else {
    cout << "Hang the man!" << endl << "Remaining guesses: " << guessCounter << endl;
    guess();
  }
}

void newGame() {
  cout << "Welcome to the Hangman Game!" << endl,
  cout << "And may the odds be ever in your favor!" << endl << endl;
  cout << "In this game, you have to use capital english letters (A-Y)." << endl;
  hangman();
}

int main() {
  // Create a program that plays hangman  //
  // It should have a hardcoded word.
  // The user should be able to guess wrong five times  //
  // It should request for letters like:
  // Give me a letter:  //
  // If the word contains the letter:
  // As an answer it should print the word in its current form like:
  // _PP_E
  // Remaining wrong guesses: 5  //
  // If don't contains:  //
  // It should reduce the remaining wrong guesses by one, and print the error:  //
  // Wrong guess
  // Remaining wrong guesses 4  //
  // If the user ran out of guesses, it should display: Game over! :(  //
  // If the user figured out all the letters in the word it should display: You Win! :)

  newGame();

  return 0;
}


