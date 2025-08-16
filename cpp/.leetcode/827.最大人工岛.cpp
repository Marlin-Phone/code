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
            // cout << "Here! " << endl;
            dfs(a, b, grid);
            // cout << "Here! " << endl;
        }
        // cout << "idx = " << idx << endl;
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
        // for (int i = 0; i < 4; i++) {
        //     for (int j = 0; j < 4; j++) {
        //         int a1 = x + dx[i], b1 = y + dy[i];
        //         int a2 = x + dx[j], b2 = y + dy[j];
        //         if (a1 >= 0 && b1 >= 0 && a1 < n && b1 < n && a2 >= 0 &&
        //             b2 >= 0 && a2 < n && b2 < n) {
        //             // cout << "grid1 = " << grid[a1][b1] << endl;
        //             // cout << "grid2 = " << grid[a2][b2] << endl;
        //             // cout << endl;
        //             ans = max(ans, id[grid[a1][b1]]);
        //             if (grid[a1][b1] != grid[a2][b2]) {
        //                 temp = id[grid[a1][b1]] + id[grid[a2][b2]] + 1;
        //                 ans = max(ans, temp);
        //                 // cout << "ans = " << ans << endl;
        //             }
        //         }
        //     }
        //     }
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
        // for (int i = 0; i <= 3; i++) {
        //     cout << id[i] << endl;
        // }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    check(i, j, grid);
                }
            }
        }
        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < n; j++) {
        //         cout << grid[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        return ans;
    }
};
// @lc code=end
