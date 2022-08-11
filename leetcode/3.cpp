#include <bits/stdc++.h>
using namespace std;
vector<int> getMaximumXor(vector<int> &nums, int maximumBit)
{
    int maxi = (1 << maximumBit) - 1;
    // cout<<maxi<<endl;
    int n = nums.size();
    vector<int> prefix(n);
    prefix[0] = nums[0];
    for (int i = 1; i < n; i++)
    {
        prefix[i] = nums[i] ^ prefix[i - 1];
    }
    vector<int> ans;
    for (int i = n - 1; i >= 0; i--)
    {
        ans.push_back(prefix[i] ^ maxi);
    }
    return ans;
}