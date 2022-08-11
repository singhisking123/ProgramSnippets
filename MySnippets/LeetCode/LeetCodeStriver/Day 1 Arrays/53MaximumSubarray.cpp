#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
	int maxSubArray(vector<int> &nums)
	{
		int curr_sum = 0, prev_sum = 0;
		int n = nums.size();
		for (int i = 0; i < n; ++i)
		{
			curr_sum += nums[i];
			if (curr_sum < 0)
			{
				curr_sum = 0;
			}
			if (curr_sum > prev_sum)
			{
				prev_sum = curr_sum;
			}
		}
		if (prev_sum != 0)
			return prev_sum;
		else
		{
			int maxi = nums[0];
			for (int i = 1; i < n; i++)
			{
				maxi = max(maxi, nums[i]);
			}
			return maxi;
		}
		return 0;
	}
};

int main()
{
}