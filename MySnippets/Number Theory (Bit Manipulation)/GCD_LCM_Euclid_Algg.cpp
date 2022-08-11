#include <bits/stdc++.h>
using namespace std;

// function to build gcd
int gcd(int a, int b) {
	if (a == 0) return b;
	return gcd(b % a, a);
}

int main()
{
	cout << gcd(4, 12) << endl;
	// built in function is __gcd to find the greatest common divisor of number...
	cout << __gcd(50, 100) << endl;
}