// https://luogu.com.cn/problem/P1216
// DP
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(a) cout << #a << " = " << a << endl;
// #define int long long

const int N = 1010;
int T = 1;
int n;
int a[N][N];
int dp[N][N];

int dfs(int x, int y) {
    if (x == n) {
        return a[x][y];
    }
    if (dp[x][y]) {
        return dp[x][y];
    }

    int ans;
    ans = a[x][y] + max(dfs(x + 1, y), dfs(x + 1, y + 1));
    dp[x][y] = ans;

    return ans;
}
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        dp[n][i] = a[n][i];
    }

    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            dp[i][j] = a[i][j] + max(dp[i + 1][j], dp[i + 1][j + 1]);
        }
    }

    cout << dp[1][1];
    // cout << dfs(1, 1);
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