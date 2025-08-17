#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=827 lang=cpp
 *
 * [827] 最大人工岛
 */

// @lc code=start
class Solution {
  public:
    int n;
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {-1, 0, 1, 0};
    bool st[550][550];
    int id[250000];
    int idx = 1;
    int ans = 0;
    int cnt = 0;
    void dfs(int x, int y, vector<vector<int>> &grid) {
        st[x][y] = true;
        for (int i = 0; i < 4; i++) {
            int a = x + dx[i], b = y + dy[i];
            if (a < 0 || b < 0 || a >= n || b >= n) {
                continue;
            }
            if (grid[a][b] == 0) {
                continue;
            }
            if (st[a][b]) {
                continue;
            }
            st[a][b] = true;
            grid[a][b] = idx;
            cnt++;
            dfs(a, b, grid);
        }
        id[idx] = cnt;
        ans = max(ans, cnt);
    }
    void check(int x, int y, vector<vector<int>> &grid) {
        int temp = 0;
        int cnt[4] = {0};
        set<int> set1;
        for (int i = 0; i < 4; i++) {
            int a = x + dx[i], b = y + dy[i];
            if (a >= 0 && b >= 0 && a < n && b < n) {
                if (set1.count(grid[a][b])) {
                    continue;
                }
                set1.insert(grid[a][b]);
                temp += id[grid[a][b]];
            }
        }
        ans = max(ans, temp + 1);
    }

    int largestIsland(vector<vector<int>> &grid) {
        ans = 0;
        n = grid.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && !st[i][j]) {
                    grid[i][j] = idx;
                    cnt = 1;
                    dfs(i, j, grid);
                    idx++;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    check(i, j, grid);
                }
            }
        }
        return ans;
    }
};
// @lc code=end
