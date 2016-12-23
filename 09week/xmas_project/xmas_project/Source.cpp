#include "Player.h"

using namespace std;

void delay(int seconds) {
  Sleep(seconds * 1000);
}

int main(int argc, char* argv[]) {
  int delaySeconds;
  cout << "you shuld put the audio file directly to the c:\\\\ named bell.wav " << endl;
  cout << "enter the delay time in seconds \nif deafult type 0 \ndefault is 1 min" << endl;
  cin >> delaySeconds;
  cout << "after input" << delaySeconds << endl;
  delaySeconds = delaySeconds == 0 ? 60 : delaySeconds;
  cout << "after ? operand" << delaySeconds << endl;

  delay(delaySeconds);
  cout << "I'm playing..." << endl;
  Player bell("C:\\bell.wav");
  //Player bell("./bell.wav");

  bell.play();

  return 0;
}