#include <bits/stdc++.h>
using namespace std;

void printLCS(string text1, string text2) {
	int n = text1.length(), m = text2.length();
	int t[n + 1][m + 1];
	for (int i = 0; i < n + 1; i++) {
		for (int j = 0; j < m + 1; j++) {
			t[i][j] = 0;
		}
	}
	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < m + 1; j++) {
			if (text1[i - 1] == text2[j - 1]) {
				t[i][j] = t[i - 1][j - 1] + 1;
			} else {
				t[i][j] = max(t[i - 1][j], t[i][j - 1]);
			}
		}
	}
	string result;
	for (int a = 1; a < n + 1; a++) {
		for (int b = 1; b < m + 1; b++) {
			if (t[n][m] == t[a][b]) {
				int i = a, j = b;
				while (i != 0 && j != 0) {
					if (text1[i - 1] == text2[j - 1]) {
						result = text1[i - 1] + result; i--; j--;
					} else {
						if (t[i][j] == t[i - 1][j]) {
							i--;
						} else if (t[i][j] == t[i][j - 1]) {
							j--;
						}
					}
				}
				cout << result << endl;
				result = "";
			}
		}
	}
	// int i = n, j = m;
	// while (i != 0 && j != 0) {
	// 	if (text1[i - 1] == text2[j - 1]) {
	// 		result = text1[i - 1] + result; i--; j--;
	// 	} else {
	// 		if (t[i][j] == t[i - 1][j]) {
	// 			i--;
	// 		} else if (t[i][j] == t[i][j - 1]) {
	// 			j--;
	// 		}
	// 	}
	// }
	// cout << result << endl;
}

int main() {
	string s1, s2;

	cin >> s1 >> s2;
	printLCS(s1, s2);
}