#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=394 lang=cpp
 *
 * [394] 字符串解码
 */

// @lc code=start
class Solution {
  public:
    int where = 0;
    string get(int cnt, string s) {
        string ans = "";
        while (cnt--) {
            ans += s;
        }
        return ans;
    }
    string f(string &s, int i) {
        string ans = "";
        int cnt = 0;
        while (i < s.length() && s[i] != ']') {
            if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) {
                ans += s[i++];
            } else if (s[i] >= '0' && s[i] <= '9') {
                cnt = cnt * 10 + s[i++] - '0';
            } else {
                // 遇到 [
                ans += get(cnt, f(s, i + 1));
                i = where + 1;
                cnt = 0;
            }
        }
        where = i;
        return ans;
    }

    string decodeString(string s) {
        where = 0;
        return f(s, 0);
    }
};
// @lc code=end
