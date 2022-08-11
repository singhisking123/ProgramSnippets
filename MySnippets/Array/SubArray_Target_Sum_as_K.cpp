#include <bits/stdc++.h>
using namespace std;

// Find all possible subarrays whose Sum is K (target)... use prefix sum
class Solution {
public: // Very Very Important and Concept Clear Question
	// Prefix sum and y-k and k rule of ((y-k)+k) gives k which is
	// which is prefix sum
	int subarraySum(vector<int>& arr, int k) {
		int counter = 0, y = 0;
		unordered_map<int, int> um;
		um[0]++;
		for (int i = 0; i < arr.size(); i++) {
			y += arr[i];
			auto it = um.find(y - k);
			if (it != um.end()) {
				counter += it->second;
			}
			um[y]++;
		}
		return counter;
	}
//     understanded from very good teacher sumeet malik
//     https://www.youtube.com/watch?v=20v8zSo2v18&ab_channel=Pepcoding
};

int main() {

}