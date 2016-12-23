#include <windows.h>
#include <iostream>
#pragma comment(lib, "winmm.lib")

using namespace std;

int main1(int argc, char* argv[]) {
  cout<<"Sound playing... enjoy....!!!" << endl;
  PlaySound(TEXT("bell.wav"), NULL, SND_FILENAME); //SND_FILENAME or SND_LOOP

return 0;
}
