#pragma GCC optimmize("O3", "inline", "omit-frame-pointer", "unroll-loops",    \
                      "fast-math")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int ll

void solve() {
    ll s, l, r;
    cin >> s >> l >> r;
    // for (int i = 1; i <= 1000; i++) {
    //     int i_num = i * (i + 1);
    //     for (int j = 1 + i; j <= 1000; j++) {
    //         int j_num = j * (j + 1);
    //         for (int k = 1 + i + j; k <= 1000; k++) {
    //             int k_num = k * (k + 1);
    //             if (k_num == i_num * j_num) {
    //                 cout << "i = " << i << " j = " << j << " k = " << k <<
    //                 endl;
    //             }
    //         }
    //     }
    //     // cout << "i = " << i * (i + 1) << endl;
    // }
    cout << r - l + 1 << endl;
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}