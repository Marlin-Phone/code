// https://luogu.com.cn/problem/P
//
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(a) cout << #a << " = " << a << endl;
// #define int long long
// #define MOD 1000000007

const int N = 110;
int T = 1;
int t, m;
int tim[N], val[N];
int dp[N]; // i表示时间,dp[i]表示i时采到的草药的最大价值

void solve() {
    cin >> t >> m;
    for (int i = 1; i <= m; i++) {
        cin >> tim[i] >> val[i];
    }
    dfs()
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