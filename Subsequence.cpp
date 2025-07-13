// https://luogu.com.cn/problem/P
//
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(a) cout << #a << " = " << a << endl;
// #define int long long

const int N = 1e6 + 10;
int T = 1;
int n, k1, k2;
int a[N];
int diff[N];

void solve() {
    cin >> n >> k1 >> k2;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        diff[i] = abs(a[i] - a[i - 1]);
    }

    for (int i = 1; i <= n; i++) {
        cout << diff[i] << " ";
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