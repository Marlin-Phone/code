// https://luogu.com.cn/problem/P
//
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(a) cout << #a << " = " << a << endl;
// #define int long long
// #define MOD 1000000007

// const int N = 2e5 + 10;
int T = 1;
int n;
int a, b;

void solve() {
    cin >> a >> b;
    if (a > 0) {
        if (b > 0) {
            cout << "NorthEast" << endl;
            return;
        } else {
            cout << "NorthWest" << endl;
        }
    } else {
        if (b > 0) {
            cout << "SouthEast" << endl;
        } else {
            cout << "SouthWest" << endl;
        }
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