// https://luogu.com.cn/problem/P2840
// DP
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(a) cout << #a << " = " << a << endl;
// #define int long long
#define MOD 1000000007;

const int N = 1e4 + 10;
int T = 1;
int n, w;
int a[N];
int dp[N];

int dfs(int money) {
    if (money == 0) {
        return 1;
    }
    if (dp[money]) {
        return dp[money];
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] > money) {
            continue;
        }
        ans = (ans + dfs(money - a[i])) % MOD;
    }
    dp[money] = ans;

    return ans;
}
void solve() {
    cin >> n >> w;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    dp[0] = 1;
    for (int i = 1; i <= w; i++) {
        int temp;
        for (int j = 1; j <= n; j++) {
            if (a[j] > i) {
                continue;
            }
            temp = (temp + dp[i - a[j]]) % MOD;
        }
        dp[i] = temp;
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