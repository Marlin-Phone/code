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
    struct DSU {
        vector<int> fa;
        int sets;
        DSU(int n) : fa(n) {
            for (int i = 0; i < n; i++) {
                fa[i] = i;
            }
        }
        int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
        bool merge(int x, int y) {
            x = find(x);
            y = find(y);
            if (x == y) {
                return false;
            }
            fa[x] = y;
            return true;
        }
    };
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    int numIslands(vector<vector<char>> &grid) {
        int ans = 0;
        int n = grid.size();
        int m = grid[0].size();
        DSU dsu(n * m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    dsu.sets++;
                    if (j > 0 && grid[i][j - 1] == '1') {
                        if (dsu.merge(i * m + j, i * m + j - 1))
                            dsu.sets--;
                    }
                    if (i > 0 && grid[i - 1][j] == '1') {
                        if (dsu.merge(i * m + j, (i - 1) * m + j))
                            dsu.sets--;
                    }
                }
            }
        }
        return dsu.sets;
    }
};
// @lc code=end
