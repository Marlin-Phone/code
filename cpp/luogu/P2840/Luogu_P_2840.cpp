// https://luogu.com.cn/problem/P2840
// DP 记忆化搜索
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(a) cout << #a << " = " << a << endl;
// #define int long long
#define MOD 1000000007

const int N = 1e5 + 10;
int T = 1;
int n, w;
int a[N];
int dp[N];

int dfs(int i) {
    if (i == 0) {
        return 1;
    }
    if (dp[i]) {
        return dp[i];
    }
    int ans = 0; // ans就是dp[i]就是支付方式数量
    for (int j = 1; j <= n; j++) {
        if (i < a[j]) {
            continue;
        }
        ans = (ans + dfs(i - a[j])) % MOD;
    }
    dp[i] = ans;
    return ans;
}
void solve() {
    cin >> n >> w;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    dp[0] = 1;
    for (int i = 1; i <= w; i++) {
        for (int j = 1; j <= n; j++) {
            if (i < a[j]) {
                continue;
            }
            dp[i] = (dp[i] + dfs(i - a[j])) % MOD;
        }
    }
    cout << dp[w];
    // cout << dfs(w);
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