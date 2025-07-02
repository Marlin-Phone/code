// https://luogu.com.cn/problem/P
//
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(a) cout << #a << " = " << a << endl;
// #define int long long

const int N = 110;
int T = 1;
double n, s;
double t[N];

void solve() {
    cin >> n >> s;
    for (int i = 1; i <= n; i++) {
        cin >> t[i];
    }
    for (int i = 0; i < n; i++) {
        if (t[i + 1] - t[i] >= s + 0.5) {
            cout << "No" << endl;
            return;
        }
    }

    cout << "Yes" << endl;
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