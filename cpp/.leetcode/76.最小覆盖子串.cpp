/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */

// @lc code=start
class Solution {
  public:
    string minWindow(string s, string t) {
        int debt = 0;
        int cnt[256] = {0};
        string ans = "";
        for (int i = 0; i < t.size(); i++) {
            debt++;
            cnt[t[i]]--;
        }
        int len = INT_MAX;
        int left = 0;
        for (int l = 0, r = 0; r < s.size(); r++) {
            if (cnt[s[r]] < 0) {
                cnt[s[r]]++;
                debt--;
            } else {
                cnt[s[r]]++;
            }
            if (debt == 0) {
                while (cnt[s[l]] > 0) {
                    cnt[s[l++]]--;
                }
                if (len > r - l + 1) {
                    len = r - l + 1;
                    left = l;
                }
            }
        }
        return len == INT_MAX ? "" : s.substr(left, len);
    }
};
// @lc code=end
