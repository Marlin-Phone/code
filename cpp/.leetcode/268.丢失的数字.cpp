/*
 * @lc app=leetcode.cn id=268 lang=cpp
 *
 * [268] 丢失的数字
 */

// @lc code=start
class Solution {
  public:
    int missingNumber(vector<int> &nums) {
        int ans = 0;
        int n = nums.size();
        // 得到nums数组的异或和，nums数组中有n个数字（缺失了一个），范围在[0, n]
        for (int i = 0; i < n; i++) {
            ans ^= nums[i];
        }
        // 得到0~n的异或和，共n + 1个数字
        for (int i = 0; i <= n; i++) {
            ans ^= i;
        }
        // ans即为缺失的数字
        return ans;
    }
};
// @lc code=end
