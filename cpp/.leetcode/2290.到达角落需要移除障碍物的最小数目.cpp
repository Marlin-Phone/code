#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=2290 lang=cpp
 *
 * [2290] 到达角落需要移除障碍物的最小数目
 */

// @lc code=start
class Solution {
  public:
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {-1, 0, 1, 0};
    int minimumObstacles(vector<vector<int>> &grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> distance(m, vector<int>(n, INT_MAX));
        deque<pair<int, int>> dque;
        dque.push_back({0, 0});
        distance[0][0] = 0;
        while (!dque.empty()) {
            auto [x, y] = dque.front();
            dque.pop_front();
            if (x == m - 1 && y == n - 1) {
                return distance[x][y];
            }
            for (int i = 0; i < 4; i++) {
                int a = x + dx[i];
                int b = y + dy[i];
                if (a < 0 || b < 0 || a >= m || b >= n) {
                    continue;
                }
                if (distance[a][b] <= distance[x][y] + grid[a][b]) {
                    continue;
                }
                distance[a][b] = distance[x][y] + grid[a][b];
                if (grid[a][b] == 1) {
                    dque.push_back({a, b});
                } else {
                    dque.push_front({a, b});
                }
            }
        }
        return -1;
    }
};
// @lc code=end
