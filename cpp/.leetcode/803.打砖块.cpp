#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=803 lang=cpp
 *
 * [803] 打砖块
 */

// @lc code=start
class Solution {
  public:
    vector<int> ans;
    vector<vector<int>> g;
    vector<vector<int>> h;
    int n, m;
    // 从(x, y)出发，遇到1就感染成2
    // 统计新增了几个2
    int dfs(int x, int y) {
        if (x < 0 || y < 0 || x == n || y == m || g[x][y] != 1) {
            return 0;
        }
        g[x][y] = 2;
        return 1 + dfs(x + 1, y) + dfs(x, y + 1) + dfs(x - 1, y) +
               dfs(x, y - 1);
    }

    bool worth(int i, int j) {
        return g[i][j] == 1 &&
               (i == 0 || (i > 0 && g[i - 1][j] == 2) ||
                (i < n - 1 && g[i + 1][j] == 2) ||
                (j > 0 && g[i][j - 1] == 2) || (j < m - 1 && g[i][j + 1] == 2));
    }

    vector<int> hitBricks(vector<vector<int>> &grid,
                          vector<vector<int>> &hits) {
        g = grid;
        h = hits;
        n = grid.size();
        m = grid[0].size();
        ans = vector<int>(hits.size(), 0);
        if (n == 1) {
            return ans;
        }
        for (int i = 0; i < hits.size(); i++) {
            int a = hits[i][0];
            int b = hits[i][1];
            g[a][b]--;
        }
        for (int i = 0; i < m; i++) { // 对天花板洪水填充
            dfs(0, i);
        }
        for (int i = h.size() - 1, row, col; i >= 0; i--) {
            row = h[i][0];
            col = h[i][1];
            g[row][col]++;
            if (worth(row, col)) {
                ans[i] = dfs(row, col) - 1;
            }
        }
        return ans;
    }
};
// @lc code=end
