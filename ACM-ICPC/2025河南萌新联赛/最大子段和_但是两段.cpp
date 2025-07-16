// https://luogu.com.cn/problem/P
//
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(a) cout << #a << " = " << a << endl;
// #define int long long

const int N = 5e3 + 10;
int T = 1;
int a, b, c1, c2, c3;
int dp[N];

void solve() {
    cin >> a >> b >> c1 >> c2 >> c3;

    /*
    dp[x+1] = min(dp[x+1], dp[x] + C1)   [当x+1<=max_bound]
    dp[x-1] = min(dp[x-1], dp[x] + C2)   [当x-1>=0]
    dp[2*x] = min(dp[2*x], dp[x] + C3)   [当2*x<=max_bound]
    */
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