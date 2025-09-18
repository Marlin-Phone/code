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

int x, y;

int f(int num) {
    string str_num = to_string(num);
    for (int i = str_num.size() - 1; i >= 0; i--) {
        if (str_num[i] == '0') {
            str_num.pop_back();
        } else {
            break;
        }
    }
    reverse(str_num.begin(), str_num.end());
    return stoll(str_num);
}
void solve() {
    cin >> x >> y;
    vector<int> a(15);
    a[1] = x;
    a[2] = y;
    for (int i = 3; i <= 10; i++) {
        a[i] = f(a[i - 1] + a[i - 2]);
        // dbg(a[i]);
    }
    cout << a[10] << endl;
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