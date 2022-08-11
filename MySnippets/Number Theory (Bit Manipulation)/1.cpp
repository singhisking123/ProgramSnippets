#include <bits/stdc++.h>
using namespace std;

void printBinary(int num) {
	for (int i = 10; i >= 0; i--) {
		cout << ((num >> i) & 1) ;
	}
	cout << endl;
}

int main()
{
	int num = 8;
	printBinary(num);
	num |= 1 << 5;
	printBinary(num);
}