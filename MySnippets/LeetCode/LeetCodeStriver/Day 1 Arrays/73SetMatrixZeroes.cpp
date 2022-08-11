#include <bits/stdc++.h>
using namespace std;

// My code Implement by me
void setZeroes(vector<vector<int>>& matrix) {
	int m = matrix.size();
	int n = matrix[0].size();
	vector<bool> rows(m, false);
	vector<bool> cols(n, false);
	// cout << m << " " << n << endl;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (matrix[i][j] == 0) {
				rows[i] = true;
				cols[j] = true;
			}
		}
	}
	for (int i = 0; i < m; i++) {
		if (rows[i] == true) {
			for (int a = 0; a < n; a++) {
				matrix[i][a] = 0;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		if (cols[i] == true) {
			for (int b = 0; b < m; b++) {
				matrix[b][i] = 0;
			}
		}
	}

}




int main() {
	unordered_set<int> row, col;
	// store rows and columns and then in last make these
	// these rows and columns all set to zero fully
	/*
		if r in row_set or c in column_set {
				cell[r][c] = 0
		}
	}*/

}