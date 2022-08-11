#include <bits/stdc++.h>
using namespace std;

class Solution {
public: // Aree wah wah wah wha !! what a solution by lee215
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        int n = nums.size();
        stack<int> st;
        vector<int> res(n, -1);
        for (int i = 0; i < n * 2; ++i)
        {
            while (st.size() && nums[st.top()] < nums[i % n])
            {
                res[st.top()] = nums[i % n];
                st.pop();
            }
            st.push(i % n);
        }
        return res;
    }
};

int main()
{
}