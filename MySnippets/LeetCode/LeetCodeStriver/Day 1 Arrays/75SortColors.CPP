#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	void sortColors(vector<int>& nums) {
		int n = nums.size();
		int count0 = 0, count1 = 0, count2 = 0;
		for (int i = 0; i < n; i++) {
			if (nums[i] == 0) {
				count0++;
			} else if (nums[i] == 1) {
				count1++;
			} else {
				count2++;
			}
		}
		for (int i = 0; i < n; i++) {
			if (count0 != 0) {
				nums[i] = 0; count0--;
			}
			else if (count1 != 0) {
				nums[i] = 1; count1--;
			}
			else if (count2 != 0) {
				nums[i] = 2; count2--;
			}
		}
	}
};



int main() {

}

