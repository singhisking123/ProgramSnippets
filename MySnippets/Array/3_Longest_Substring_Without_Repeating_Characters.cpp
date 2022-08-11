#include <bits/stdc++.h>
using namespace std;
// Very Very Important Question
// Acquire and release Technique
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int n = s.length(), i = -1, j = -1;
		unordered_map<char, int> um;
		while (true) {
			bool f1 , f2 ;
			f1 = f2 = false;
			// acquire
			while (i < n) {
				f1 = true;
				i++;
				um[s[i]]++;

				auto it = um.find(s[i]);
				if (it->second == 2 ) {
					break;
				} else {
					int len = i - j;
					if (len > ans) {
						ans = len;
					}
				}
			}
			// release
			while (j < i) {
				f2 = true;
				j++;
				um[s[j]]--;
				auto it = um.find(s[j]);
				if ((it->second) == 1) {
					break;
				}
			}
			if (f1 == false && f2 == false) {
				break;
			}
		}
	}
};

int main() {

}