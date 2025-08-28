#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
class Solution {
  public:
    int trap(vector<int> &height) {
        int n = height.size();
        vector<int> leftMax(n);
        vector<int> rightMax(n);
        int lmax = 0;
        int rmax = 0;
        for (int i = 0; i < n; i++) {
            leftMax[i] = lmax;
            lmax = max(lmax, height[i]);
        }
        for (int i = n - 1; i >= 0; i--) {
            rightMax[i] = rmax;
            rmax = max(rmax, height[i]);
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int temp = min(leftMax[i], rightMax[i]) - height[i];
            temp = max(temp, 0);
            ans += temp;
        }
        return ans;
    }
};
// @lc code=end
