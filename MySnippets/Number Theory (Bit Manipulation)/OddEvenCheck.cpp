#include <bits/stdc++.h>
using namespace std;

// 2 se divisible when the last digit is zero
// Not divisible when last digit is 1

void divisibleBy2(int n) {
	if (n & 1) { // doing & with 0000001 gives the last digit as 0 or 1
		cout << "odd" << endl;
	}
	else {
		cout << "even" << endl;
	}
}



int main()
{
	divisibleBy2(4);
	/*Multiply Divide by 2*/
	int n = 5;
	cout << (n >> 1) << endl; // divided by 2
	cout << (n << 1) << endl; // multiplied by 2
	// 2 (10) becomes 4(100) and becomes 8(100) when further multiplies
}