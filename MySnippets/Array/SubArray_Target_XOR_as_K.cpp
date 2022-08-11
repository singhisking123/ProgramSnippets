#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &arr, int k) {
	int counter = 0, y = 0;
	unordered_map<int, int> um;
	um[0]++;
	for (int i = 0; i < arr.size(); i++) {
		y ^= arr[i];
		auto it = um.find(y ^ k);
		if (it != um.end()) {
			counter += it->second;
		}
		um[y]++;
	}
	return counter;
}


int main() {
	int n;
	cin >> n;

	vector<int> arr(n);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	for (int x : arr) cout << x << " " ;
	cout << endl;
	int x =  solve(arr, 5);
	cout << x << endl;
}