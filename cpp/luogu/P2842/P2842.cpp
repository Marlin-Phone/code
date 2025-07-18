// https://luogu.com.cn/problem/P2842
// DP 记忆化搜索
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(a) cout << #a << " = " << a << endl;
// #define int long long

const int N = 1e4 + 10;
int T = 1;
int n, w;
int a[N];
vector<int> dp(N, 1e9);

int dfs(int x) {
    if (x == 0) {
        return 0;
    }
    if (dp[x] != 1e9) {
        return dp[x];
    }
    int ans = 1e9;
    for (int i = 1; i <= n; i++) {
        if (x < a[i]) {
            continue;
        }
        ans = min(ans, 1 + dfs(x - a[i]));
    }
    dp[x] = ans;
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
            if (i < a[j]) {
                continue;
            }
            dp[i] = min(dp[i], 1 + dp[i - a[j]]);
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