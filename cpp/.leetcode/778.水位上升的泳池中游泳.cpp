#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=778 lang=cpp
 *
 * [778] 水位上升的泳池中游泳
 */

// @lc code=start
class Solution {
  public:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    int swimInWater(vector<vector<int>> &grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dis(n, vector<int>(m, INT_MAX));
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>, greater<>>
            heap;
        dis[0][0] = grid[0][0];
        heap.push({dis[0][0], {0, 0}});
        while (!heap.empty()) {
            auto [d, t] = heap.top();
            heap.pop();
            int x = t.first;
            int y = t.second;
            if (d > dis[x][y]) {
                continue;
            }
            if (x == n - 1 && y == m - 1) {
                return d;
            }
            for (int i = 0; i < 4; i++) {
                int a = x + dx[i];
                int b = y + dy[i];
                if (a < 0 || b < 0 || a >= n || b >= m) {
                    continue;
                }
                int w = max(grid[a][b], d);
                if (dis[a][b] > w) {
                    dis[a][b] = w;
                    heap.push({dis[a][b], {a, b}});
                }
            }
        }
        return -1;
    }
};
// @lc code=end
