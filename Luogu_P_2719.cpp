#include <bits/stdc++.h>
// #pragma GCC optimize("O3", "inline", "omit-frame-pointer", "unroll-loops",     \
//                      "fast-math")
using namespace std;

// Types
#define ll long long
#define int ll
#define float double
// Aliases
#define x first
#define y second
#define endl '\n'
// Math
#define mod(x) ((x + MOD) % MOD)
// Debug
#define dbg(a) cout << "Dbg: " << #a << " = " << a << endl;

// const db eps = 1e-8;
// const int MOD = 1e9 + 7;
const int N = 1250;

int n;
double dp[N][N];

void solve() {
    cin >> n;
    n /= 2;
    for (int i = 2; i <= n; i++) {
        dp[0][i] = dp[i][0] = 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = 1.0 / 2 * (dp[i - 1][j] + dp[i][j - 1]);
        }
    }
    printf("%.4lf", dp[n][n]);
    // for (int i = 1; i <= n; i++) {
    //     cout << "i = " << i << endl;
    //     dbg(dp[i][i]);
    //     cout << endl;
    // }
}

signed main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}