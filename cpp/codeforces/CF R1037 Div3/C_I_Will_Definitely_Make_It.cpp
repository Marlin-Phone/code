// https://luogu.com.cn/problem/P
//
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(a) cout << #a << " = " << a << endl;
#define int long long

const int N = 1e5 + 10;
int T = 1;
int n, k;
int h[N];

void solve() {
    int maxh = -1, idx = -1, sth = -1;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
        if (maxh < h[i]) {
            maxh = h[i];
        }
    }
    sth = h[k];
    // debug(h[k]);

    sort(h + 1, h + 1 + n);

    for (int i = 1; i <= n; i++) {
        if (sth == h[i]) {
            idx = i;
        }
    }
    // debug(sth);
    // debug(maxh);

    // for (int i = 1; i <= n; i++) {
    //     cout << h[i] << " ";
    // }
    // cout << endl;

    // debug(idx);
    for (int i = idx; i < n; i++) {
        if (h[i + 1] - h[i] > sth) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
    return;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}