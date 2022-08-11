#include <bits/stdc++.h>
using namespace std;


int main()
{
	/*   HACKS    */
	/*	Compute the biggest power of 2 that is a divisor of x. Example: f(12) = 4 */
	// 1 << __builtin_ctz(x)
	/*  Compute the smallest power of 2 that is not smaller than x. Example: f(12) = 16*/
	// 1 << (32 - __builtin_clz (x - 1))
	// but this is UB (undefined behavior) for x≤1 so you'll often need an if for x==1
}