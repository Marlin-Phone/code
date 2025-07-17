#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int f1(string &s, int i, vector<int> &dp) {
        if (i == s.size()) {
            return 1;
        }
        if (dp[i] != -1) {
            return dp[i];
        }
        int ans;
        if (s[i] == '0') {
            ans = 0;
        } else {
            ans = f1(s, i + 1, dp);
            if (i + 1 < s.size() &&
                ((s[i] - '0') * 10 + s[i + 1] - '0') <= 26) {
                ans += f1(s, i + 2, dp);
            }
        }
        dp[i] = ans;
        return ans;
    }

    int numDecodings(string s) {
        // vector<int> dp(s.size() + 10, -1);
        int n = s.size();
        // dp[n] = 1;
        int cur;
        int next = 1;     // dp[i + 1]
        int nextNext = 0; // dp[i + 2]
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '0') {
                // dp[i] = 0;
                cur = 0;
            } else {
                // dp[i] = dp[i + 1];
                cur = next;
                if (i + 1 < n && ((s[i] - '0') * 10 + s[i + 1] - '0' <= 26)) {
                    // dp[i] += dp[i + 2];
                    cur += nextNext;
                }
            }
            nextNext = next;
            next = cur;
        }
        return cur;
        // return dp[0];
        // return f1(s, 0, dp);
    }
};

int main() { return; }