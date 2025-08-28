#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=1368 lang=cpp
 *
 * [1368] 使网格图至少有一条有效路径的最小代价
 */

// @lc code=start
class Solution {
  public:
    int dx[5] = {0, 0, 0, 1, -1}; // 1右 2左 3下 4上
    int dy[5] = {0, 1, -1, 0, 0};
    int minCost(vector<vector<int>> &grid) {
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
            for (int i = 1; i <= 4; i++) {
                int a = x + dx[i];
                int b = y + dy[i];
                int w = grid[x][y] == i ? 0 : 1; // 箭头指向i位置为0，否则为1
                if (a < 0 || b < 0 || a >= m || b >= n) {
                    continue;
                }
                if (distance[a][b] <= distance[x][y] + w) {
                    continue;
                }
                distance[a][b] = distance[x][y] + w;
                if (w == 1) {
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
