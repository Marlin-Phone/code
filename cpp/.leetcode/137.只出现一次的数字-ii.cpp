/*
 * @lc app=leetcode.cn id=137 lang=cpp
 *
 * [137] 只出现一次的数字 II
 */

// @lc code=start
class Solution {
  public:
    int singleNumber(vector<int> &nums) {
        int ans = 0;
        int cnt[32] = {0};
        for (auto num : nums) {
            for (int i = 0; i < 32; i++) {
                if (num & (1 << i)) {
                    cnt[i]++;
                }
            }
        }
        for (int i = 0; i < 32; i++) {
            if (cnt[i] % 3) {
                ans |= (1 << i);
            }
        }
        return ans;
    }
};
// @lc code=end
