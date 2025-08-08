/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution {
  public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        int ch[256] = {0};
        for (int l = 0, r = 0; r < s.size(); r++) {
            if (ch[s[r]] == 0) {
                ch[s[r]]++;
                ans = max(ans, r - l + 1);
            } else {
                ch[s[r]]++;
                while (ch[s[r]] != 1) {
                    ch[s[l++]]--;
                }
            }
        }
        return ans;
    }
};
// @lc code=end
