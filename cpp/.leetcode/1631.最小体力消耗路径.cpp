#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=1631 lang=cpp
 *
 * [1631] 最小体力消耗路径
 */

// @lc code=start
class Solution {
  public:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    int minimumEffortPath(vector<vector<int>> &heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> dis(n, vector<int>(m, INT_MAX));
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>, greater<>>
            heap;
        dis[0][0] = 0;
        heap.push({0, {0, 0}});
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
                int w = abs(heights[a][b] - heights[x][y]);
                int new_max = max(d, w);
                if (dis[a][b] > new_max) {
                    dis[a][b] = new_max;
                    heap.push({dis[a][b], {a, b}});
                }
            }
        }
        return dis[n - 1][m - 1];
    }
};
// @lc code=end
