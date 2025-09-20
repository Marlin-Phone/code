#include <bits/stdc++.h>
// #pragma GCC optimize("O3", "inline", "omit-frame-pointer", "unroll-loops",     \
//                      "fast-math")
using namespace std;

// Types
#define ll long long
#define int ll
#define float double
// Aliases
#define x first
#define y second
#define endl '\n'
// Math
#define mod(x) ((x + MOD) % MOD)
// Debug
#define dbg(a) cout << "Dbg: " << #a << " = " << a << endl;

// const double eps = 1e-8;
// const int MOD = 1e9 + 7;
// const int N = 1e6 + 10;

int n, r;

string ten2r(int num) {
    string res;
    // int wei = 0;
    while (num != 0) {
        int temp = num % r;
        dbg(temp);
        if (-10 < temp && temp < 10) {
            res.push_back('0' + temp);
        } else {
            res.push_back('A' + temp - 10);
        }
        num /= r;
        // wei++;
    }
    dbg(res);
    reverse(res.begin(), res.end());
    return res;
}

void solve() {
    cin >> n >> r;
    string str_num = ten2r(n);
    // cout << 30000 / (-2) << endl;
    cout << n << "=" << str_num << "(base" << r << ")" << endl;
}

signed main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}