// https://luogu.com.cn/problem/P
//
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(a) cout << #a << " = " << a << endl;
// #define int long long

const int N = 2e5 + 10;
int T = 1;
int n, j, k;
// int a[N];

void solve() {
    cin >> n >> j >> k;
    vector<int> a(n + 10, 0);
    int maxnum = -1;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        maxnum = max(maxnum, a[i]);
    }
    int val = a[j];
    sort(a.begin() + 1, a.begin() + 1 + n);
    int idxl = lower_bound(a.begin() + 1, a.begin() + 1 + n, val) - a.begin();
    int idxr = upper_bound(a.begin() + 1, a.begin() + 1 + n, val) - a.begin();
    // debug(val);
    // debug(idxl);
    // debug(idxr);
    // debug(k);
    // debug(maxnum);
    if (k != 1) {
        cout << "YES" << endl;
    } else {
        if (val == maxnum) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    // for (int i = 1; i <= n; i++) {
    //     cout << a[i] << " ";
    // }
    // cout << endl;
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