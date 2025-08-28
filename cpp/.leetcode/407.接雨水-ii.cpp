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
    int dx[4] = {};
    int dy[4] = {};
    priority_queue<tuple<int, int, int>,
                   vector<tuple<int, int, int>, greater<tuple<int, int, int>>>>
        heap;
    int trapRainWater(vector<vector<int>> &heightMap) {
        int n = heightMap.size();
        int m = heightMap[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 || j == 0 || i == n - 1 || j == m - 1) {
                }
            }
        }
    }
};
// @lc code=end
