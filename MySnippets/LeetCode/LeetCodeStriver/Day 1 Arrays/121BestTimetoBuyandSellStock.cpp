#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        int prev_max = INT_MIN;
        vector<int> prefixSum(n);
        for (int i = n - 1; i >= 0; --i)
        {
            prefixSum[i] = max(prices[i], prev_max);
            prev_max = prefixSum[i];
        }
        int res = INT_MIN;
        for (int i = n - 1; i >= 0; --i)
        {
            res = max((prefixSum[i] - prices[i]), res);
        }
        return res;
    }
};

int main()
{
}