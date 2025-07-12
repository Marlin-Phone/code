// https://luogu.com.cn/problem/P
//
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(a) cout << #a << " = " << a << endl;
// #define int long long

// const int N =
int T = 1;
int n, l, r, x, y;

void solve() {
    int cnt = 0;
    cin >> n >> l >> r;
    for (int i = 1; i <= n; i++) {
        cin >> x >> y;
        if (x <= l && r <= y) {
            cnt++;
        }
    }
    cout << cnt;
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