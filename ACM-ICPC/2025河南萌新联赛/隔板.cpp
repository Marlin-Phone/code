// https://luogu.com.cn/problem/P
//
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(a) cout << #a << " = " << a << endl;
#define int long long
#define MOD 998244353

const int N = 5010;
int T = 1;
int n, m;
int dp[N][N];
int dp1[N];

int getn1(int n) {
    int num = 1;
    for (int i = 1; i <= n; i++) {
        num = (num * i) % MOD;
    }
    return num;
}
void solve() {
    cin >> n;
    cin >> m;
    if (n < m) {
        cout << 0 << endl;
        return;
    }
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i][j] = (dp[i - 1][j - 1] + j * dp[i - 1][j]) % MOD;
        }
    }

    cout << (dp[n][m] * getn1(m)) % MOD;
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