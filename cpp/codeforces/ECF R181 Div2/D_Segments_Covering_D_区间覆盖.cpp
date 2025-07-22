// https://luogu.com.cn/problem/P
//
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(a) cout << #a << " = " << a << endl;
// #define int long long

const int MOD = 998244353;
const int N = 2e5 + 10;
int T = 1;
int n, m;
int l[N], r[N], p[N], q[N];

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> l[i] >> r[i] >> p[i] >> q[i];
    }
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