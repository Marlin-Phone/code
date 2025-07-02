// https://luogu.com.cn/problem/P
//
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(a) cout << #a << " = " << a << endl;
// #define int long long

const int N = 1e6 + 10;
int T = 1;
int n, m;
int diff[N];
int s[N];
int minnum = INT_MAX;

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int l, r;
        cin >> l >> r;
        diff[l] += 1;
        // if (r + 1 < n) {
        diff[r + 1] -= 1;
        // }
    }
    for (int i = 1; i <= n; i++) {
        s[i] = s[i - 1] + diff[i];
        minnum = min(minnum, s[i]);
    }
    cout << minnum << endl;
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