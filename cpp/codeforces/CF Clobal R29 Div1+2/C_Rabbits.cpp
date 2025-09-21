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

int n;
string str;

void solve() {
    cin >> n;
    cin >> str;
    bool valid = true;

    for (int i = 0; i < n; i++) {
        if (str[i] == '0') {
            if (i == 0 || i == n - 1) {
                continue;
            }
            if (str[i - 1] == '1' && str[i + 1] == '1') {
                if ((i - 2 >= 0 && str[i - 2] == '0') ||
                    (i + 2 < n && str[i + 2] == '0')) {
                    continue;
                } else {
                    valid = false;
                    break;
                }
            }
        }
    }

    cout << (valid ? "YES" : "NO") << '\n';
}

signed main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
        // dbg(t);
    }

    return 0;
}