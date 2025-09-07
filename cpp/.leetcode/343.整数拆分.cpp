#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=343 lang=cpp
 *
 * [343] 整数拆分
 */

// @lc code=start
class Solution {
  public:
    long long fast_pow(long long x, long long n) {
        long long ans = 1;
        while (n != 0) {
            if ((n & 1) == 1) {
                ans *= x;
            }
            x *= x;
            n >>= 1;
        }
        return ans;
    }
    int integerBreak(int n) {
        if (n == 2) {
            return 1;
        }
        if (n == 3) {
            return 2;
        }
        long long cnt3 = 0;
        if (n % 3 == 0) {
            cnt3 = n / 3;
            return fast_pow(3, cnt3);
        } else if (n % 3 == 1) {
            cnt3 = n / 3 - 1;
            return fast_pow(3, cnt3) * 4;
        } else {
            cnt3 = n / 3;
            return fast_pow(3, cnt3) * 2;
        }
    }
};
// @lc code=end
