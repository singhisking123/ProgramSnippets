#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
	vector<vector<int>> t(1002, vector<int> (1002, -1));
	//Function to return max value that can be put in knapsack of capacity W.
	int knapSack(int W, int wt[], int val[], int n)
	{
		if (w == 0 || n == 0)
			return 0;
		if (t[n][w] != -1)
			return t[n][w];
		if (wt[n - 1] <= W)
			return t[n][w] = max(val[n - 1] + knapSack(W - wt[n - 1], wt, val, n - 1), knapSack(W, wt, val, n - 1) );
		else if (wt[n - 1] > W)
			return t[n][w] = knapSack(W, wt, val, n - 1);
	}
};

int main() {

}