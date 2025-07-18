// https://luogu.com.cn/problem/P
//
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(a) cout << #a << " = " << a << endl;
#define int long long
// #define MOD 1000000007

const int N = 2e5 + 10;
int T = 1;
int n, x, y;
int a[N], b[N];

void solve() {
    cin >> n >> x >> y;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
        if (x < a[i]) {
            cout << x << endl;
            return;
        } else {
            x -= a[i];
            x += b[i];
            if (x >= y) {
                cout << x;
                return;
            }
        }
    }
    cout << x;
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