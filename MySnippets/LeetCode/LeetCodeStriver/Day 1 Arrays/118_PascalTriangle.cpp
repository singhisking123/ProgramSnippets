#include <bits/stdc++.h>
using namespace std;


int main() {

}
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> v;
        vector<int> vec;
        v.push_back(vec);
        v[0].push_back(1);
        if (numRows == 1) return v;
        v.push_back(vec);
        v[1].push_back(1);  v[1].push_back(1);
        if (numRows == 2) return v;
        for (int i = 2; i < numRows; ++i) {
            v.push_back(vec);
            v[i].push_back(1);
            for (int j = 1; j < v[i - 1].size(); j++) {
                int x = v[i - 1][j - 1] + v[i - 1][j];
                v[i].push_back(x);
            }
            v[i].push_back(1);
        }



        return v;
    }
};