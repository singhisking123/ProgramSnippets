#include <bits/stdc++.h>
using namespace std;
void dfs(int i, int j, int rows, int cols, vector<vector<char>> &board)
{
    if (i < 0 || j < 0 || i >= rows || j >= cols || board[i][j] != 'O')
    {
        return;
    }
    board[i][j] = '-1';

    dfs(i + 1, j, rows, cols, board);
    dfs(i, j + 1, rows, cols, board);
    dfs(i - 1, j, rows, cols, board);
    dfs(i, j - 1, rows, cols, board);
}
void solve(vector<vector<char>> &board)
{
    set<pair<int, int>> set;
    int n = board.size(), m = board[0].size();
    for (int i = 0; i < m; i++)
    {
        if (board[0][i] == 'O')
        {
            dfs(0, i, n, m, board);
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (board[i][m - 1] == 'O')
        {
            dfs(i, m - 1, n, m, board);
        }
    }
    for (int i = m - 1; i >= 0; i--)
    {
        if (board[n - 1][i] == 'O')
        {
            dfs(n - 1, i, n, m, board);
        }
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if (board[i][0] == 'O')
        {
            dfs(i, 0, n, m, board);
        }
    }
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<m;j++)
        {
            if(board[i][j] == '-1')
            board[i][j] = 'O';
        }
    }
}