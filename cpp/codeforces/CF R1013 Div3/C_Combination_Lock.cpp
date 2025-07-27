// https://luogu.com.cn/problem/P
//
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(a) cout << #a << " = " << a << endl;
// #define int long long

// const int MOD = 1e9 + 7;
// const int N = 2e5 + 10;
int T = 1;
int n;

void solve() {
    cin >> n;
    if (n % 2 == 0) {
        cout << -1 << endl;
        return;
    }

    int num = 1;
    for (int i = 1; i <= n; i++) {
        cout << num << " ";
        num += 2;
        if (num > n) {
            num = 2;
        }
    }
    cout << endl;
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