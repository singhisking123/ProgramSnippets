#include <iostream>
using namespace std;

// array --> 2, 5, 1, 8, 2, 9, 1
// k --> 3

int solve (vector<int> & arr)
{

	int i = 0, j = 0, mx = INT_MIN, n = arr.size();
	int sum = 0;
	while (j < n)
	{
		sum = sum + arr[j];
		if (j - i + 1  < k) {
			j++;
		}
		else if (j - i + 1 == k) {
			mx = max(mx, sum);
			i++; j++;
			sum = sum - arr[i - 1];
		}
	}
}

int main()
{
	return 0;
}