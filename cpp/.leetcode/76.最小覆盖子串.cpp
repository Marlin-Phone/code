/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */

// @lc code=start
class Solution {
  public:
    string minWindow(string s, string t) {
        int ans = INT_MAX;
        int debt = t.size();
        int cnts[256] = {0};
        for (int i = 0; i < t.size(); i++) {
            cnts[t[i]]--;
        }
        int len = INT_MAX;
        int start = 0;
        for (int l = 0, r = 0; r < s.size(); r++) {
            if (cnts[s[r]]++ < 0) {
                debt--;
            }
            if (debt == 0) {
                while (cnts[s[l]] > 0) {
                    cnts[s[l++]]--;
                }
                if (r - l + 1 < len) {
                    len = r - l + 1;
                    start = l;
                }
            }
        }
        return len == INT_MAX ? "" : s.substr(start, len);
    }
};
// @lc code=end
