// https://luogu.com.cn/problem/P
//
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(a) cout << #a << " = " << endl;
// #define int long long

const int N = 15;
int T = 1;
int n, x;
int a[N];

void solve() {
    cin >> n >> x;
    int flagbg = 0, flaged = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] == 1) {
            flaged = i;
            if (flagbg == 0) {
                flagbg = i;
            }
        }
    }
    int length = flaged - flagbg + 1;
    if (length <= x) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
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