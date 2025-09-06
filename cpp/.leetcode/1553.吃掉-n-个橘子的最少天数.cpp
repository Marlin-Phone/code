#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=1553 lang=cpp
 *
 * [1553] 吃掉 N 个橘子的最少天数
 */

// @lc code=start
class Solution {
  public:
    unordered_map<int, int> dp;
    int dfs(int n) {
        if (n <= 1) {
            return 1;
        }
        if (dp[n]) {
            return dp[n];
        }
        // (n % 2 + 1 + dfs(n / 2)) 尽快让橘子被2整除
        // (n % 3 + 1 + dfs(n / 3)) 尽快让橘子被3整除
        int ans = min(n % 2 + 1 + dfs(n / 2), n % 3 + 1 + dfs(n / 3));
        dp[n] = ans;
        return ans;
    }
    int minDays(int n) { return dfs(n); }
};
// @lc code=end
