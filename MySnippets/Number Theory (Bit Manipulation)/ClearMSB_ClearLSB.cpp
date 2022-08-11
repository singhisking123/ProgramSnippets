#include <bits/stdc++.h>
using namespace std;

void printBinary(int num) {
	for (int i = 10; i >= 0; i--) {
		cout << ((num >> i) & 1);
	}
	cout << endl;
}

void powerof2(int n) {
	if (n & (n - 1))
		cout << "Not Power of 2 " << endl;
	else
		cout << "Yes Power of 2 " << endl;
}


int main()
{
	printBinary(59);
	int a = 59;
	int i = 4; // we have to clear LSB from 0 to 4 of 59
	/*
		00000111011 is binary of 59
		11111100000 & is to be used for clearing lsb
		00000011111 se paa sakte upar wala
		00000100000-1 se paa sakte upar wala THINKING PROCESS


	*/
	cout << (a & (~((1 << (i + 1) - 1)))) << endl;

	// WE have to clear MSB of a
	int c = (a & ((1 << (i + 1)) - 1));
	printBinary(c);

	powerof2(8);
	powerof2(9);
}