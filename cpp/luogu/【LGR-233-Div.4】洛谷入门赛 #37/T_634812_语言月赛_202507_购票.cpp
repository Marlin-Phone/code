// https://luogu.com.cn/problem/P
//
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(a) cout << #a << " = " << a << endl;
#define int unsigned long long
// #define MOD 1000000007

// const int N = 2e5 + 10;
int T = 1;
int n, a, b;

void solve() {
    cin >> n >> a >> b;

    if (n == 0 || a == 0 || b == 0) {
        cout << 0 << endl;
        return;
    }

    if (n < b / a) {
        cout << n * a;
    } else {
        cout << b;
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