#include <bits/stdc++.h>
using namespace std;


int main()
{
	/*
	1 0 -- > 1
	0 1 -- > 1
	0 0 -- > 0
	1 1 -- > 0

	x^ x == 0
	x^ 0 == x
	*/
	int a = 4, b = 6;
// swap wali likha hai
	a = a ^ b;
	b = b ^ a; // b --> a
	// b = b ^ (a ^ b) ==> b ^ b ^ a

	a = a ^ b; // a --> b
	// a = (a^ b)^ a ==> a^a^b --> b

	// Even wali chizon ko zero bna deta hai zor aur odd number of
	// chizein bachi rhti hain....
	// Let's say {2,2,3,3,4,4,5,6,6}
	// Taking XOR 2^2^3^3^4^4^5^6^6 --> 0^0^0^5^0 --> 5
	/*

	LINKS TO QUESTION FIRST SEE THIS OF XOR TO BE CLEAR

	 	https://leetcode.com/problems/missing-number/
	 	https://leetcode.com/problems/single-number/
	 	https://leetcode.com/problems/find-the-difference/

	*/

}