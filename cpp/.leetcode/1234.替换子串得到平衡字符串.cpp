#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=1234 lang=cpp
 *
 * [1234] 替换子串得到平衡字符串
 */

// @lc code=start
class Solution {
  public:
    int balancedString(string s) {
        int debt = 0;
        int n = s.size();
        map<char, int> cnts;
        for (int i = 0; i < s.size(); i++) {
            cnts[s[i]]++;
        }
        for (auto &[c, cnt] : cnts) {
            if (cnt < n / 4) {
                cnt = 0;
            } else {
                cnt = n / 4 - cnt;
                debt -= cnt;
            }
        }
        if (debt == 0) {
            return 0;
        }
        int ans = INT_MAX;
        for (int l = 0, r = 0; r < s.size(); r++) {
            if (cnts[s[r]]++ < 0) {
                debt--;
            }
            if (debt == 0) {
                while (cnts[s[l]] > 0) {
                    cnts[s[l++]]--;
                }
                ans = min(ans, r - l + 1);
            }
        }
        return ans;
    }
};
// @lc code=end
