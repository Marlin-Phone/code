// https://luogu.com.cn/problem/P
//
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(a) cout << #a << " = " << a << endl;
// #define int long long

// const int N =
int T = 1;
int x;

void solve() {
    cin >> x;
    int minnum = 1e9;
    while (x > 0) {
        int temp = x % 10;
        x /= 10;
        minnum = min(minnum, temp);
    }
    cout << minnum << endl;
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