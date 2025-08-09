#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=922 lang=cpp
 *
 * [922] 按奇偶排序数组 II
 */

// @lc code=start
class Solution {
  public:
    vector<int> sortArrayByParityII(vector<int> &nums) {
        int even = 1, odd = 0;

        int cur = nums.size() - 1;
        while (even < nums.size() && odd < nums.size()) {
            if (nums[cur] % 2 == 0) {
                swap(nums[odd], nums[cur]);
                odd += 2;
            } else {
                swap(nums[even], nums[cur]);
                even += 2;
            }
        }
        return nums;
    }
};
// @lc code=end
