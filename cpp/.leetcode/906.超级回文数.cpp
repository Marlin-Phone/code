#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=906 lang=cpp
 *
 * [906] 超级回文数
 */

// @lc code=start
class Solution {
  public:
    bool ishuiwen(long long num, long long l, long long r) {
        if (l <= num && num <= r) {
        } else {
            return false;
        }
        long long num0 = num;
        long long ans = 0;
        while (num0 != 0) {
            ans *= 10;
            ans += num0 % 10;
            num0 /= 10;
        }
        return num == ans;
    }
    long long gethuiwenodd(long long num) { // 奇数
        long long num0 = num;
        num0 /= 10;
        while (num0 != 0) {
            num *= 10;
            num += num0 % 10;
            num0 /= 10;
        }
        return num;
    }
    long long gethuiweneven(long long num) { // 偶数
        long long num0 = num;
        while (num0 != 0) {
            num *= 10;
            num += num0 % 10;
            num0 /= 10;
        }
        return num;
    }
    bool safeSquare(long long num) {
        return num <=
               static_cast<long long>(sqrt(numeric_limits<long long>::max()));
    }
    int superpalindromesInRange(string left, string right) {
        long long l = stoll(left);
        long long r = stoll(right);
        // long long sqrt_left = (long long)sqrt(lleft);
        long long limit = (long long)sqrt(r);
        long long seed = 1;
        long long num = 0; // num^2 -> x
        long long ans = 0;
        do {
            num = gethuiweneven(seed);
            if (num <= limit && safeSquare(num) && ishuiwen(num * num, l, r)) {
                ans++;
            }
            num = gethuiwenodd(seed);
            if (num <= limit && safeSquare(num) && ishuiwen(num * num, l, r)) {
                ans++;
            }
            seed++;
        } while (num < limit);

        return ans;
    }
};
// @lc code=end
