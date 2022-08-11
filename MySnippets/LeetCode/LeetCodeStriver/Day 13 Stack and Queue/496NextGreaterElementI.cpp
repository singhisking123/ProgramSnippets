#include <bits/stdc++.h>
using namespace std;

class Solution {
public: // very important --> question of stack ---> remember
// learn from luv --> https://www.youtube.com/watch?v=T-E3hWEPWWU&ab_channel=Luv
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int, int> um;
        vector<int> res;
        for(int i=0;i<nums2.size();i++) {
            while(!st.empty() && nums2[st.top()] < nums2[i]) {
                um[nums2[st.top()]] = nums2[i];
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty()) {
            um[nums2[st.top()]] = -1;
            st.pop();
        }
        for(int i=0;i<nums1.size();i++) {
            auto it = um.find(nums1[i]);
            res.push_back(it->second);
        }
        return res;
    }
};

int main() {

}