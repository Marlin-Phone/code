#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=803 lang=cpp
 *
 * [803] 打砖块
 */

// @lc code=start
class Solution {
  public:
    vector<int> res;
    int n;
    void diff1(vector<vector<int>> &grid, vector<vector<int>> &hits) {
        for (int i = 0; i < n; i++)
    }
    vector<int> hitBricks(vector<vector<int>> &grid,
                          vector<vector<int>> &hits) {
        n = hits.size();
        res.resize(n);
        diff1(grid, hits);
    }
};
// @lc code=end
