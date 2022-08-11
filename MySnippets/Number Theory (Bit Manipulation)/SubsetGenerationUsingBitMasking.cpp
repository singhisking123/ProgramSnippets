#include <bits/stdc++.h>
using namespace std;

/* https://leetcode.com/problems/subsets/ */


void printBinary(int num) {
	for (int i = 10; i >= 0; i--) {
		cout << ((num >> i) & 1) ;
	}
	cout << endl;
}
///////// O(n * (2^n)) ///////////Time Complexity
vector<vector<int>> subsets(vector<int>& nums) {
	// Doing by Second Approach Using Bit Masking
	// See the previous approach in previous submission
	int n = nums.size();
	int subsetCount = 1 << n;	 //pow(2,n);
	vector<vector<int>> res;
	for (int i = 0; i < subsetCount; i++) {
		vector<int> subset;
		for (int j = 0; j < n; j++) {
			if ((i & (1 << j)) == 0) {}
			else subset.push_back(nums[j]);
		}
		res.push_back(subset);
	}
	return res;

}



int main()
{
	vector<int> v;
	int n, x; cin >> n;
	while (n--) {
		cin >> x; v.push_back(x);
	}
	vector<vector<int>> res = subsets(v);
	for (auto subset : res) {
		for (auto a : subset)
			cout << a << " ";
		cout << endl;
	}
}