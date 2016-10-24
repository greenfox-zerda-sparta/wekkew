#include <iostream>
#include <string>

using namespace std;

int main() {
	int ab = 123;
	int credits = 100;
	bool isBonus = False;
	// if credits are at least 50,
	// and is_bonus is False decrement ab by 2

	// if credits are smaller than 50,
	// and is_bonus is False decrement ab by 1

	// if is_bonus is True ab should remain the same
	if (!isBonus) {
		if (credits >= 50) {
			ab-=2;
		}
		else {
			ab--;
		}
	}
	return 0;
}
