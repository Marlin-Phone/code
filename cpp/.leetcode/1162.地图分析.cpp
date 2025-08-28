#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=1162 lang=cpp
 *
 * [1162] 地图分析
 */

// @lc code=start
class Solution {
  public:
    static const int N = 1e3 + 10;
    int n, m;
    int ans;
    int st[N][N];
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {-1, 0, 1, 0};
    queue<tuple<int, int, int>> que;
    void bfs() {
        while (!que.empty()) {
            auto [x, y, cnt] = que.front();
            que.pop();
            for (int i = 0; i < 4; i++) {
                int a = x + dx[i];
                int b = y + dy[i];
                if (a < 0 || b < 0 || a >= n || b >= m) {
                    continue;
                }
                if (st[a][b]) {
                    continue;
                }
                st[a][b] = 1;
                ans = max(ans, cnt + 1);
                que.push({a, b, cnt + 1});
            }
        }
    }
    int maxDistance(vector<vector<int>> &grid) {
        grid = grid;
        n = grid.size();
        m = grid[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    st[i][j] = 1;
                    que.push({i, j, 1});
                }
            }
        }
        bfs();
        return ans - 1;
    }
};
// @lc code=end
