#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=878 lang=cpp
 *
 * [878] 第 N 个神奇数字
 */

// @lc code=start
class Solution {
  public:
    const int mod = 1e9 + 7;
    typedef long long ll;
    ll __lcm(ll a, ll b) { return a * b / __gcd(a, b); }
    ll f(ll x, ll a, ll b) { return x / a + x / b - x / __lcm(a, b); }
    int nthMagicalNumber(int n, int a, int b) {
        if (a > b) {
            swap(a, b);
        }
        ll maxnum = (ll)n * a;
        ll l = 0, r = maxnum;
        while (l + 1 != r) {
            ll m = (l + r) / 2;
            if (f(m, a, b) >= n) {
                r = m;
            } else {
                l = m;
            }
        }
        return r % mod;
    }
};
// @lc code=end
