#include <bits/stdc++.h>
using namespace std;

// fun code to print the binary of a number
void printBinary(int num) {
	for (int i = 10; i >= 0; i--) {
		cout << ((num >> i) & 1);
	}
	cout << endl;
}


int main()
{
	for (int i = 0; i <= 10; i++)
		printBinary(i);

	cout << endl;
	// Printing the binary of space
	printBinary(' ');// Used to Uppar to Lowar Case (|)
	// Printing the binary of underscore
	printBinary('_');// Used to Lower to Uppar Case (&)

	cout << endl;

	printBinary(-1);
}
