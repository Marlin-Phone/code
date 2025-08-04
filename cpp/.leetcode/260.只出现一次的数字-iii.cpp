/*
 * @lc app=leetcode.cn id=260 lang=cpp
 *
 * [260] 只出现一次的数字 III
 */

// @lc code=start
class Solution {
  public:
    vector<int> singleNumber(vector<int> &nums) {
        long long eor1 = 0, eor2 = 0;
        for (auto num : nums) {
            eor1 ^= num;
        }
        // eor1即为a^b
        long long diff = eor1 & -eor1;
        for (auto num : nums) {
            if ((num & diff) == diff) {
                eor2 ^= num;
            }
        }
        // 此时eor2即为 a 或 b
        int a = eor2;
        int b = eor1 ^ eor2;
        return {a, b};
    }
};
// @lc code=end
