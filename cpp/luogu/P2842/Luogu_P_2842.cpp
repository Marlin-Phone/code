// https://luogu.com.cn/problem/P2842
// DP
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(a) cout << #a << " = " << a << endl;
// #define int long long

const int N = 1e4 + 10;
int T = 1;
int n, w;
int a[N];
vector<int> dp(N, 1e9); // i为金额,dp[i]为纸币张数
vector<int> memo(N, -1);

int dfs(int amount) {
    if (amount == 0)
        return 0;
    if (amount < 0)
        return INT_MAX;
    if (memo[amount] != -1)
        return memo[amount];

    int res = INT_MAX;
    for (int j = 1; j <= n; j++) {
        int coin = a[j];
        int temp = dfs(amount - coin);
        if (temp != INT_MAX) {
            res = min(res, 1 + temp);
        }
    }
    return memo[amount] = res;
}
int f1(int i) { // dp[i]表示纸币张数 i表示金额
    if (i == 0) {
        return 0;
    }
    if (i < 0) {
        return 1e9;
    }
    if (dp[i] != -1) {
        return dp[i];
    }

    int ans = INT_MAX;
    for (int j = 1; j <= n; j++) {
        ans = min(ans, 1 + f1(i - a[j]));
    }
    dp[i] = ans;
    return ans;
}

void solve() {
    cin >> n >> w;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    dp[0] = 0;
    for (int i = 1; i <= w; i++) {
        for (int j = 1; j <= n; j++) {
            if (i >= a[j]) {
                dp[i] = min(dp[i], 1 + dp[i - a[j]]);
            }
        }
    }
    cout << dp[w] << endl;
    // cout << f1(w) << endl;
    // cout << dfs(w) << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}