#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=407 lang=cpp
 *
 * [407] 接雨水 II
 */

// @lc code=start
class Solution {
  public:
    struct Cmp {
        bool operator()(const tuple<int, int, int> &a,
                        const tuple<int, int, int> &b) {
            return get<2>(a) > get<2>(b);
        }
    };
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, Cmp>
        heap;
    int trapRainWater(vector<vector<int>> &heightMap) {
        int n = heightMap.size();
        int m = heightMap[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 || j == 0 || i == n - 1 || j == m - 1) {
                    heap.push({i, j, heightMap[i][j]});
                    visited[i][j] = true;
                } else {
                    visited[i][j] = false;
                }
            }
        }
        int ans = 0;
        while (!heap.empty()) {
            auto [x, y, w] = heap.top();
            heap.pop();
            ans += w - heightMap[x][y];
            for (int i = 0; i < 4; i++) {
                int a = x + dx[i];
                int b = y + dy[i];
                if (a < 0 || b < 0 || a >= n || b >= m) {
                    continue;
                }
                if (visited[a][b]) {
                    continue;
                }
                heap.push({a, b, max(heightMap[a][b], w)});
                visited[a][b] = true;
            }
        }
        return ans;
    }
};
// @lc code=end
