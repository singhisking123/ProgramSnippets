#include <bits/stdc++.h>
using namespace std;

// Not Working for the 10^12 values like 999966000289 should give YES but gives NO

int main() {
	long long n;
	cin >> n;
	vector<long long> v(n);
	for (long long i = 0; i < n; i++) {
		cin >> v[i];
		// cout << v[i] << " ";
	}

	for (long long i = 0; i < n; i ++) {
		long long low = 2, high = v[i] - 1;
		long long mid, count = 0;
		while (low <= high) {
			mid = low + high;
			mid = mid >> 1;
			if (v[i] % mid == 0) {
				count++;
				if (count > 1)break;
				high = mid - 1;
			} else {
				high = mid - 1;
			}
		}
		if (count == 1) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}