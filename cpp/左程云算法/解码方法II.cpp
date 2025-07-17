#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007;

class Solution {
  public:
    long long f1(string &s, int i, vector<long long> &dp) {
        if (i == s.size()) {
            return 1;
        }

        if (s[i] == '0') {
            return 0;
        }

        if (dp[i] != -1) {
            return dp[i];
        }

        long long ans = f1(s, i + 1, dp) * (s[i] == '*' ? 9 : 1);

        if (i + 1 < s.size()) {
            if (s[i] != '*') {
                if (s[i + 1] != '*') {
                    if ((s[i] - '0') * 10 + s[i + 1] - '0' <= 26) {
                        ans += f1(s, i + 2, dp);
                    }
                } else {
                    if (s[i] == '1') {
                        ans += f1(s, i + 2, dp) * 9;
                    }
                    if (s[i] == '2') {
                        ans += f1(s, i + 2, dp) * 6;
                    }
                }
            } else {
                if (s[i + 1] != '*') {
                    if (s[i + 1] <= '6') {
                        ans += f1(s, i + 2, dp) * 2;
                    } else {
                        ans += f1(s, i + 2, dp);
                    }
                } else {
                    ans += f1(s, i + 2, dp) * 15;
                }
            }
        }
        ans = ans % 1000000007;
        dp[i] = ans;
        return dp[i];
    }
    int numDecodings(string s) {
        vector<long long> dp(s.size(), -1);
        return f1(s, 0, dp);
    }
};