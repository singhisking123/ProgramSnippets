#include <bits/stdc++.h>
using namespace std;

void convert() {

}




int main()
{
	char A = 'A';
	char a = A | (1 << 5);
	cout << a << endl; // Thus converted into lowerCase

	char x = (a & (~(1 << 5)));
	cout << x << endl; // Thus convert into upperCase

	/* can use the ' ' to convert upper to lower
	   can use the '_' to convert lower to upper */
	char B = 'B';
	char b = B | ' ';
	cout << b << endl;

	char y = b & '_' ;
	cout << y << endl;
}