#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;

/// Use Iterative Code prefreably in Competitive Contests
int binExpIterative(int a, int b) {
	int ans = 1;
	while (b > 0) {
		if (b & 1) {
			ans = (ans * 1LL * a) % M;
		}
		a = (a * 1LL * a) % M;
		b >>= 1;

	}
	return ans ;
}
/// Recursive Code
int binExpRecur(int a, int b) {
	if (b == 0) return 1;
	long res = binExpRecur(a, b / 2);
	if (b & 1) {
		return (a * ((res * res) % M)) % M;
	} else {
		return (res * 1LL * res) % M;
	}
}

int main() {
	int x = binExpIterative(2, 9);
	cout << x << endl;

}