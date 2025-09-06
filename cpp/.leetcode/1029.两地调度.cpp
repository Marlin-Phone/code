#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=1029 lang=cpp
 *
 * [1029] 两地调度
 */

// @lc code=start
class Solution {
  public:
    int twoCitySchedCost(vector<vector<int>> &costs) {
        int sum = 0;
        vector<int> arr(costs.size());
        for (int i = 0; i < costs.size(); i++) {
            arr[i] = costs[i][1] - costs[i][0];
            sum += costs[i][0];
        }
        sort(arr.begin(), arr.end());
        for (int i = 0; i < costs.size() / 2; i++) {
            sum += arr[i];
        }
        return sum;
    }
};
// @lc code=end
