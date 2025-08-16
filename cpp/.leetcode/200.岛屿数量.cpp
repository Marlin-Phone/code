#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

// @lc code=start
class Solution {
  public:
    int n, m;
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    bool st[350][350];

    void dfs(vector<vector<char>> &grid, int x, int y) {
        st[x][y] = true;
        for (int i = 0; i < 4; i++) {
            int a = x + dx[i];
            int b = y + dy[i];
            if (a < 0 || a >= n || b < 0 || b >= m) {
                continue;
            }
            if (st[a][b]) {
                continue;
            }
            if (grid[a][b] == '0') {
                continue;
            }
            st[a][b] = true;
            dfs(grid, a, b);
        }
    }

    int numIslands(vector<vector<char>> &grid) {
        n = grid.size(), m = grid[0].size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1' && !st[i][j]) {
                    ans++;
                    st[i][j] = true;
                    dfs(grid, i, j);
                }
            }
        }
        return ans;
    }
};
// @lc code=end
