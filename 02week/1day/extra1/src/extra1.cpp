#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
	// takes a number and convert it to roman number
	int arabic;
	cout << "Please, add a number:" << endl;
	cin >> arabic;

	int work = arabic;
	string roman = "";

	int m = floor(work / 1000);
	for (int i = 0; i < m; i++) {
		roman += "M";
		work -= 1000;
	}

	int c = floor(work / 100);
	if (c == 9 || c == 4) {
		if (floor(work/100 == 9)) {
			roman += "CM";
			work -= 900;
		}
		else {
			roman += "CD";
			work -= 400;
		}
	}
	else {
		int d = floor(work / 500);
		for (int i = 0; i < d; i++) {
			roman += "D";
			work -= 500;
		}
		int cent = floor(work / 100);
		for (int i = 0; i < cent; i++) {
			roman += "C";
			work -= 100;
		}
	}

	int x = floor(work/10);
	if (x == 4 || x == 9) {
		if (x == 4) {
			roman += "XL";
			work -= 40;
		}
		else {
			roman += "XC";
			work -= 90;
		}
	}
	else {
		int l = floor(work / 50);
		for (int i = 0; i < l; i++) {
			roman += "L";
			work -= 50;
		}
		int dec = floor(work / 10);
		for (int i = 0; i < dec; i++) {
			roman += "X";
			work -= 10;
		}
	}

	int uno = work/1;
	if (uno == 4 || uno == 9) {
		if (uno == 9) {
			roman += "IX";
			work -= 9;
		}
		else {
			roman += "IV";
			work -= 4;
		}
	}
	else {
		int v = floor(work / 5);
		for (int i = 0; i < v; i++) {
			roman += "V";
			work -= 5;
		}
		int one = floor(work / 1);
		for (int i = 0; i < one; i++) {
			roman += "I";
			work -= 1;
		}
	}
	if (work == 0) {
		cout << roman;
	}
	else {
		cout << "elkúrtad!!!";
	}

	return 0;
}
