// https://luogu.com.cn/problem/P
//
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(a) cout << #a << " = " << a << endl;
// #define int long long

const int N = 2e5 + 10;
int T = 1;
int n, x, p;

void solve() {
    cin >> x >> p;
    int temp = p / x;
    int temp1 = p % x;

    if (temp1 == 0) {
        cout << (temp - 1) * 2 + 1 << endl;
        return;
    } else {
        cout << (p - temp) * 2 << endl;
        return;
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