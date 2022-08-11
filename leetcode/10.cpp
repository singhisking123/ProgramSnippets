#include <bits/stdc++.h>
using namespace std;
int maxDistance(vector<vector<int>>& grid) {
        vector<pair<int,int>>zeros,ones;
        for(int i = 0;i<grid.size();i++)
        {
            for(int j = 0;j<grid[0].size();j++)
            {
                if(grid[i][j]==0)
                zeros.push_back({i,j});
                else
                ones.push_back({i,j});
            }
        }
        int res = 0;
        for(auto&x:zeros)
        {
            int mini = INT_MAX;
            for(auto &y:ones)
            {
                mini = min(mini,abs(x.first-y.first)+abs(x.second-y.second));
            }
            res = max(res,mini);
        }
        return res;
    }