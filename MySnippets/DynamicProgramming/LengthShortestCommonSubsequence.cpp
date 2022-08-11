#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
	//Function to find length of shortest common supersequence of two strings.
	int shortestCommonSupersequence(string X, string Y, int m, int n)
	{
		int t[n][m];
		memset(t, 0, sizeof(t));
		for (int i = 1; i < n + 1; i++) {
			for (int j = 1; j < m + 1; j++) {
				if(X[i-1] == Y[j-1]) {
					t[i][j] = t[i][j] + 1;
				} else {
					t[i][j] = max(t[i-1][j], t[i][j-1]);
				}
			}
		}
		return m+n-t[n][m];
	}
};

int main() {

}